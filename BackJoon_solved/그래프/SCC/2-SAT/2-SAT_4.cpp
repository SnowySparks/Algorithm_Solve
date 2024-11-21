#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int inf = 2e5+20;
int v, e;
int node_id[inf]; //scc DST (dft spanning tree 순서입력)
int id = 0;//node_id 입력을 위한 변수
bool isscc[inf];
vector<int> adj[inf];
// vector<vector<int> > scc_list; //scc 집단모임
int scc_id[inf]; //각 노드 SCC집합 요소
int scc_cnt = 0; //scc 그룹 수
stack<int> st;
int tonode(int n) {
    if (n > 0) return 2*n-1;
    else return 2*(-n);
}

int SCC(int node) {
    st.push(node);
    node_id[node] = ++id;

    int p = node_id[node];
    for (int nxt : adj[node]) {
        if (node_id[nxt] == 0) p = min(p, SCC(nxt));
        else if (!isscc[nxt]) p = min(p, node_id[nxt]);
    }

    if (p == node_id[node]) {
        ++scc_cnt;
        while(1) {
        int t = st.top(); st.pop();
        scc_id[t] = scc_cnt;
        isscc[t] = true;
        if ( t == node) break;
        }
    }
    return p;
}
//SCC 그룹 내에서 x, not x가 같이 있는 경우는 모순 -> 무조건 F가 되게 만드는 요인
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> v >> e;
    for (int i = 0 ; i < e; ++i) {
        int x1, x2;
        cin >> x1 >> x2;

        // x1 v x2 == (~x1 -> x2) , (~x2 -> x1)
        adj[tonode(-x1)].push_back(tonode(x2));
        adj[tonode(-x2)].push_back(tonode(x1));
    }

    for (int i = 1; i <= 2*v; ++i) {
        if (node_id[i] == 0) SCC(i);
    }
//  cout << '\n';
//   for (int i = 1; i <= 2*v ; ++i) {
//     cout << scc_id[i] <<' ';
//   }
//   cout << '\n';

    for (int i = 1; i <= v; ++i) {
        int x1 = tonode(i);
        int not_x1 = tonode(-i);
        if (scc_id[x1] == scc_id[not_x1]) {
        cout << 0;
        return 0;
        }
    }
    cout << 1 <<'\n';
    for (int i = 1; i <= v; ++v) {
        cout <<( scc_id[tonode(i)] < scc_id[tonode(-i)] )<<' ';
    }
    return 0;
}

  //타잔 알고리즘으로 생성된 scc_list들은 위상정렬순서의 역순으로 모아짐
  //p -> q 에서 p가 true면 q는 무조건 true지만, p가 false이면 q는 상관이 없어짐을 이용
  //위상 정렬상 해당 2-sat가 존재한다면 false -> true는 존재해도 (scc그룹간) true-> false 존재x

  //따라서 역순으로 판단하고 먼저 드러난 순서 기준으로 해당 node가 어떠한 논리값에 가지면 False 되도록 셋팅
  // p가 False를 만드는 원리

  // for (int i = scc_cnt-1; i>=0; --i) {
  //   for (int &nd : scc_list[i]) {
  //     int lg = tologic(nd);
  //     if (logic_val[abs(lg)] == -1) {
  //       if ( lg > 0) logic_val[abs(lg)] = 0;
  //       else logic_val[abs(lg)] = 1;
  //     }
  //   }
  // }

  //혹은 scc_id값이 클수록 위상정렬에서 우위이므로, 이를 이용한 판단도 가능
  //~p 가 더 높은 위치이면 p가 가능한 True여야 유리, p이면 False이어야 유리