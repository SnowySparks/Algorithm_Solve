#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n;
int dp[100001][2];
vector<int> adj[100001];

void dfs(int node, int pnode) {
    dp[node][1]++;
    for (int child : adj[node]) {
        if (child == pnode) continue;
        dfs(child, node);

        dp[node][1] += min(dp[child][0], dp[child][1]);
        dp[node][0] += dp[child][1];
    }

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}