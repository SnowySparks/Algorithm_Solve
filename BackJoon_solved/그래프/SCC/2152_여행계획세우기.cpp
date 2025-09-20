#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e4, M = 1e5;
int n, m, s, t; // 도시수, 간선수, 시작도시, 끝 도시
vector<int> adj[N+1]; //인접그래프

int visitCounter = 0; //scc 방문순서
int sccGroupCnt = 0; // scc 그룹 총 수
int dfs_number[N+1]; // dfs 첫 방문 순서
int scc_number[N+1]; //scc 번호부여
int scc_size[N+1];
int dp[N+1]; // 위상정렬 dp최소
stack<int> st;

vector<int> sccAdj[N+1];
bool sccGroupVisit[N+1];
int sccGroupIndegree[N+1];

int dfs(int node) {
    st.push(node);
    int minVisitNumber = dfs_number[node] = ++visitCounter;
    for (int &nxtNode : adj[node]) {
        if (!dfs_number[nxtNode]) minVisitNumber = min(minVisitNumber, dfs(nxtNode));
        else if (!scc_number[nxtNode]) minVisitNumber = min(minVisitNumber, dfs_number[nxtNode]);
    }
    if (minVisitNumber == dfs_number[node]) { //현재 노드 == 가장 먼저방문 가능 노드
        ++sccGroupCnt;
        while (true)
        {
            int stackNode = st.top();
            st.pop();
            scc_number[stackNode] = sccGroupCnt;
            ++scc_size[sccGroupCnt];

            if (stackNode == node) break;
        }
    }
    return minVisitNumber;
}

void init_scc() {
    for (int i = 1; i <= n; ++i) {
        if (!dfs_number[i]) dfs(i);
    }
}

void bfs_simulation() {
    queue<int> q;
    int startLoc = scc_number[s];
    dp[startLoc] = scc_size[startLoc];
    q.push(startLoc);
    while (!q.empty())
    {
        int loc = q.front(); q.pop();
        for (int nxt : sccAdj[loc]) {
            if (dp[nxt] < scc_size[nxt] + dp[loc]) {
                dp[nxt] = scc_size[nxt] + dp[loc];
                q.push(nxt);
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);

    cin >> n >> m >> s >> t;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    init_scc();

    if (sccGroupCnt == 1) {
        //모두 다 같은 scc그룹 -> 무조건 다 전부 이동 가능
        cout << n;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int &nxtNode : adj[i]) {
            if ( scc_number[i] == scc_number[nxtNode] ) continue;
            
            sccAdj[scc_number[i]].push_back(scc_number[nxtNode]);
            sccGroupIndegree[scc_number[nxtNode]]++;
        }
    }
    bfs_simulation();

    cout << dp[scc_number[t]];
    
    return 0;
}