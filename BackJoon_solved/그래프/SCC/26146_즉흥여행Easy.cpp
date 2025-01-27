#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 1;
int n, m;
vector<int> adj[maxn];
int dfsn[maxn]; //방문순서
int scc_idx[maxn];
int idx = 0;
int scc_cnt;
stack<int> st;

int dfs(int node) {
    st.push(node);
    dfsn[node] = ++idx;
    int min_visitVal = dfsn[node];
    for (int child : adj[node]) {
        if (!dfsn[child]) {
            min_visitVal = min(min_visitVal, dfs(child));
        }
        else if (!scc_idx[child]) {
            min_visitVal = min(min_visitVal, dfsn[child]);
        }
    }
    if (min_visitVal == dfsn[node]) {
        ++scc_cnt;
        while (true)
        {
            int nd = st.top(); st.pop();
            scc_idx[nd] = scc_cnt;
            if (nd == node) break;
        }
    }
    return min_visitVal;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        if (!dfsn[i] || scc_idx[i] != 1) {
            cout << "No";
            return 0;
        }
    }
    cout <<"Yes";
    return 0;
}