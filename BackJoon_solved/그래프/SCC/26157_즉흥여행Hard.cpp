#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
const int maxn = 2e5 + 1;
int n, m;
vector<int> adj[maxn];
int dfsn[maxn]; //방문순서
int scc_idx[maxn];
int idx = 0;
int scc_cnt; // scc그룹 개수
stack<int> st;

vector<int> scc_adj[maxn]; //scc
set<int> check[maxn];
int indegree[maxn];

int dfs(int node) {
    st.push(node);
    dfsn[node] = ++idx;
    int p = dfsn[node];
    for (int child : adj[node]) {
        if (!dfsn[child]) {
            p = min(p, dfs(child));
        }
        else if (!scc_idx[child]) {
            p = min(p, dfsn[child]);
        }
    }

    if (p == dfsn[node]) {
        ++scc_cnt;
        while (true)
        {
            int t = st.top(); st.pop();
            scc_idx[t] = scc_cnt;
            if (t == node) break;
        }  
    }
    return p;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (!dfsn[i]) dfs(i);
    }

    //  단 1개밖에없다 전부탐색해도 -> 다 사이클 -> 종료
    if (scc_cnt == 1) {
        cout << n << '\n';
        for (int i = 1; i <= n; ++i) cout << i <<' ';
        return 0;
    }

    // SCC 그룹끼리 위상정렬 구축하기
    for (int i = 1; i <= n; ++i) {
        for (int child : adj[i]) {
            if (scc_idx[i] == scc_idx[child]) continue;
            if (scc_idx[child] == 0) continue;
            if (check[scc_idx[i]].find(scc_idx[child]) != check[scc_idx[i]].end()) continue;
            check[scc_idx[i]].insert(scc_idx[child]);
            scc_adj[scc_idx[i]].push_back(scc_idx[child]);
            indegree[scc_idx[child]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= scc_cnt; ++i) {
        if (!indegree[i]) q.push(i);
    }

    if (q.size() != 1) {
        cout << 0;
        return 0;
    }
    vector<int> vis;
    while (!q.empty())
    {
        int node = q.front(); q.pop();
        vis.push_back(node);
        for (int child_scc : scc_adj[node]) {
            indegree[child_scc]--;
            if (indegree[child_scc] == 0) {
                q.push(child_scc);
            }
        }

        if (q.size() != 1) break;
    }
    if (!q.empty() || vis.size() != scc_cnt) {
        cout << 0;
        return 0;
    }

    int ansNodeCnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (scc_idx[i] == vis[0]) ++ansNodeCnt;
    }
    cout << ansNodeCnt << '\n';

    for (int i = 1; i <= n; ++i) {
        if (scc_idx[i] == vis[0]) cout << i << ' ';
    }

    return 0;
}