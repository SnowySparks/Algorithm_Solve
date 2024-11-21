#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int inf = 1e5+1;
bool isdone[inf];
int node_visit_order[inf];
int N, M;
vector<int> adj[inf];
stack<int> st;
int id = 0;
int ans = 0;
//vector<vector<int> > scc_list;
int scc_indegree[inf]; //idx = SCC그룹번호, 해당 그룹번호에서 indegree 정도
int scc_id[inf]; //해당 노드가 어느 SCC그룹에 있는지 기록
int scc_cnt; //scc그룹 총 수
//scc그룹 간의 위상정렬이 가능.
//타잔 알고리즘은. 위상정렬의 역순으로 scc_sublist가 담겨짐

//reset
void reset(int node) {
    for (int i = 0; i <= node; ++i) adj[i].clear();
    memset(node_visit_order,0,sizeof(node_visit_order));
    memset(scc_indegree,0,sizeof(scc_indegree));
    fill(isdone, isdone + node+1, false);
    id = 0;
    ans = 0;
    scc_cnt = 0;
}

//타잔 알고리즘 응용
int SCC(int node) {
    st.push(node);
    node_visit_order[node] = ++id; //등록순 번호
    int p = node_visit_order[node]; //등록순 번호 기준 부모값. 초기는 자기자신
    
    for (int next : adj[node]) {
        if (node_visit_order[next] == 0) p = min(p, SCC(next));
        else if (!isdone[next]) p = min(p, node_visit_order[next]);
    }
    //자기자신이 최상위 등록번호일때 자기자신 나올때까지 pop 및 등록
    if (p == node_visit_order[node]) {
        ++scc_cnt;
        while(1) {
            int t = st.top(); st.pop();
            scc_id[t] = scc_cnt;
            isdone[t] = true;
            if (t == node) break;
        }
    }
    return p;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("test_input.txt","r",stdin);
    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> M;
        reset(N);

        //input
        for (int i = 0; i < M; ++i) {
            int fr, to;
            cin >> fr >> to;
            adj[fr].push_back(to);
        }

        //simulation
        for (int i = 1; i <= N ; ++i) {
            if (!isdone[i]) SCC(i);
        }

        //topological sort
        for (int i = 1; i <= N; ++i) {
            for (int nxt : adj[i]) {
                if (scc_id[i] == scc_id[nxt]) continue;
                scc_indegree[ scc_id[nxt] ]++;
            }
        }
        for (int i = 1; i <= scc_cnt ; ++i) {
            if (!scc_indegree[i]) ++ans;
        }
        cout << ans <<'\n';
    }
    return 0;
}

//방항 비순환 그래프 (Direct Acyclic Graph)
//해당 그래프 내에서 cycle이 존재하지 않는 그래프를 지칭함
//위상 정렬 조건이 이 DAG 인 그래프여야 이기도 함

//하지만 SCC 그룹핑하고 해당 그룹끼리 위상 정렬Toplogical sorting이 가능함
//각 노드와 해당 간선들을 전부 탐색해서, 해당 노드와 그 다음 노드들 각각 어느 SCC그룹에 있는지 판단후
//SCC 그룹간 indegree관계 전부 파악