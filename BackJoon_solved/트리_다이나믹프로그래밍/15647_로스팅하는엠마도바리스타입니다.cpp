#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX_N = 3e5 + 1;
vector<pair<int ,ll> > adj[MAX_N];
int n;
ll dp[MAX_N]; // 정점 1번 기준으로 둬서, 다른 정점에 대해서 몇번 가는지
ll ans[MAX_N]; // 정점 i번 기준으로 둬서, 

ll dfs(int node, int pnode, ll pcost) { // pcost : 1번 -> node 까지의 거리
    dp[node] = 1;
    ans[1] += pcost;
    for (auto [child, cost] : adj[node]) {
        if (child == pnode) continue;   
        dp[node] += dfs(child, node, pcost + cost);
    }
    return dp[node];
}

void search(int node, int pnode, ll pre_sum, ll before_edge_cost ) {
    ans[node] = pre_sum - (dp[node]*before_edge_cost) + (dp[1]-dp[node])*before_edge_cost;
    for (auto [child, cost] : adj[node]) {
        if (child == pnode) continue;
        search(child, node, ans[node], cost);
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    int u, v; ll d;
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    dfs(1, -1, 0);
    for (auto [child, cost] : adj[1]) {
        search(child, 1, ans[1], cost);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
    return 0;
}