#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int N = 100 + 1;
const int inf = 1'000'000'007;
int n, m, k; //node, edge cnt, zero_available
vector<int> adj[N];
vector<int> order_node;
int cost[N], indegree[N], tmp[N];
bool zero[N];
int dp[N]; 
int start_node = 1, last_node = 0;
int ans = 0;

void input() {
    int a, b;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> cost[i];
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
}

void find_last_node() {
    last_node = 1;
    memcpy(tmp, indegree, sizeof(tmp));
    queue<int> q; q.push(start_node);
    dp[start_node] = cost[start_node];
    while (!q.empty())
    {
        int node = q.front();
        last_node = node;
        q.pop();
        order_node.push_back(node);
        for (int nxt : adj[node]) {
            tmp[nxt]--;
            dp[nxt] = max(dp[nxt], dp[node] + cost[nxt]);
            if (tmp[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
}

void simulation() {
    memset(dp, 0, sizeof(dp));
    dp[start_node] = cost[start_node];

    for (int node : order_node) {
        for (int nxt_node : adj[node]) {
            dp[nxt_node] = max(dp[nxt_node], dp[node] + (zero[nxt_node] ? 0 : cost[nxt_node]));
        }
    }
    ans = min(ans, dp[last_node]);
}

void back_track(int cnt, int idx) {

    if (cnt == k) {
        simulation();
        ans = min(ans, dp[last_node]);
        return;
    }

    for (int i = idx; i < n - 1; ++i) {
        zero[order_node[i]] = true;
        back_track(cnt + 1, i + 1);
        zero[order_node[i]] = false;
    }
    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    input();
    find_last_node();
    ans = dp[last_node];
    back_track(0, 1);
    cout << ans;
    return 0;
}