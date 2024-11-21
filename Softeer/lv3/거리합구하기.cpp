#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
const int inf = 2e5+ 10;
vector<pair<int ,int> > adj[inf];
int sub_node_cnt[inf]; 
ll ans[inf];

void dfs(int node, int pnode = 1, ll psum = 0) {
    sub_node_cnt[node] = 1;
    ans[1] += psum;
    for (auto &[nxt, cost] : adj[node]) {
        if (nxt == pnode) continue;
        dfs(nxt, node, psum + cost);
        sub_node_cnt[node] += sub_node_cnt[nxt];
    }
}

void solve(int node, int pnode) {
    for (auto &[nxt, cost] : adj[node]) {
        if (nxt == pnode) continue;
        ans[nxt] = ans[node] + 1LL*cost * (1LL*sub_node_cnt[1] - 2 * 1LL*sub_node_cnt[nxt]);
        solve(nxt, node);
    }
}

int main(void) {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    int fr, to, cost;

    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d %d %d",&fr,&to,&cost);
        adj[fr].push_back({to, 1LL*cost});
        adj[to].push_back({fr, 1LL*cost});
    }
    dfs(1);
    solve(1, 1);


    for (int i = 1; i <=n; ++i) {
        printf("%lld ",ans[i]);
    }

    return 0;
}
