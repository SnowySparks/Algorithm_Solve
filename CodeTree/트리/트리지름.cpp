#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int ,int>
using namespace std;
const int max_n = 1e5+1;
int n;
vector<pii> adj[max_n+1];

int tmp_node, dist = 0;

void dfs(int node, int pnode, int val) {
    if (val > dist) {
        dist = val;
        tmp_node = node;
    }

    for (auto &[nxt, cost] : adj[node]) {
        if (nxt == pnode) continue;
        dfs(nxt, node, val + cost);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int fr, to, d;
    for (int i = 0; i < n-1; ++i) {
        cin >> fr >> to >> d;
        adj[fr].push_back({to, d});
        adj[to].push_back({fr, d});
    }

    dfs(1, -1, 0);
    dist = 0;
    dfs(tmp_node, -1, 0);
    cout << dist;

    return 0;
}