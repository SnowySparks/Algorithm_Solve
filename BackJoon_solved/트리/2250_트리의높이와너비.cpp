#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//dfs bfs 2개다 사용

int parent_node[10001]; //해당 인덱스에 위치하는 값이 부모 값
vector< int > tb[10001]; //트리, 부모 -> 왼쪽 오른쪽 
int lrsize[10001][2]; //0 : 왼쪽개수, 1: 오른쪽 개수 
int locat[10001]; //실질적인 좌표, 루트는 항상 0
//자기자신 기준 왼쪽, 오른쪽 노드 개수 
//리턴값은 자기자신 + 자기자신의 왼
int dfs(int root) {
    if (lrsize[root][0]!=0 || lrsize[root][1]!=0) {
        return lrsize[root][0] + lrsize[root][1];
    }
    if (root == -1) return 0;
    lrsize[root][0] += dfs(tb[root][0]);
    lrsize[root][1] += dfs(tb[root][1]);

    return lrsize[root][0] + lrsize[root][1] +1;
}

pair<int, int> answer = {1, -1};
int high = 1;
void bfs(int root,int size) { //항상 루트 좌표를 0으로 두고 계산
    queue<pair<int ,int> > q1, q2; //현 노드, 현 노드의 부모노드 기준 왼쪽OR오른쪽 (0,1)
    int m_left, m_right, loc = 1;
    int before_size;
    pair<int, int> tp;
    q1.push({root, 2});
    before_size = q1.size();
    while(!(q1.empty())) {
        m_left = 1000000, m_right = -1000000;
        if (before_size) {
            while (before_size--) {
                tp = q1.front(); q1.pop();
                if (tp.second != 2) { //루트는 제외
                    if (tp.second == 0) locat[tp.first] = locat[parent_node[tp.first]] - lrsize[tp.first][1] -1;
                    else locat[tp.first] = locat[parent_node[tp.first]] + lrsize[tp.first][0]+1;
                }
                m_left = min(m_left, locat[tp.first]);
                m_right = max(m_right , locat[tp.first]);

                if (tb[tp.first][0] != -1) q1.push({tb[tp.first][0],0});
                if (tb[tp.first][1] != -1) q1.push({tb[tp.first][1],1});
            }
            if (answer.second < abs(m_right - m_left +1) && abs(m_left - m_right +1) <= size)  {
                answer.first = loc, answer.second = abs(m_right - m_left +1);
            }
        }
        loc++;
        before_size = q1.size();
    }
}

int main (void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int p,l,r;
    for (int i = 1; i <= N; i++) {
        cin >> p >> l >> r;
        if (l != -1) parent_node[l] = p; 
        if (r != -1) parent_node[r] = p;
        tb[p].push_back(l); tb[p].push_back(r);
    }
    int root;
    for (int i = 1; i <= N; i++) {
        if (parent_node[i] == 0) {
            root = i; break;
        }
    }
    locat[root] = 10;
    dfs(root);
    bfs(root,N);

    cout <<answer.first << ' ' <<answer.second ;

    return 0;
}