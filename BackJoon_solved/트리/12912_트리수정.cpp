#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pil = pair<int, ll>;
ll ans = -1;
vector<pil> adj[2000]; // 다음노드, 비용
int n;
struct E {
    int fr; int to; ll cost;
};
vector<E> edges;

int block1, block2; // 두 간선 사이를 막는 것

int maxNode;
ll calDist;
void dfs(int node, int pnode, ll w) {
    if (calDist < w) {
        calDist = w;
        maxNode = node;
    }
    for (auto [nextNode, nextCost] : adj[node]) {   
        if (nextNode == pnode) continue;
        if (node == block1 && nextNode == block2) continue;
        if (node == block2 && nextNode == block1) continue;
        dfs(nextNode, node, w + nextCost);
    }
};

ll calRange(int node) {
    ll res = 0;
    maxNode = -1;
    calDist = 0;
    dfs(node, -1, 0);

    calDist = 0;
    dfs(maxNode, -1, 0);
    res = calDist;
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    edges.resize(n-1);
    int fr, to; ll c;
    for (E&edge : edges) {
        cin >> edge.fr >> edge.to >> edge.cost;
        adj[edge.fr].push_back({edge.to, edge.cost});
        adj[edge.to].push_back({edge.fr, edge.cost});
    }
    ll ans = 0;
    for (E&edge : edges) {
        block1 = edge.fr; block2 = edge.to;
        ll range_1 = calRange(block1);
        ll range_2 = calRange(block2);
        ans = max(ans, range_1 + range_2 + edge.cost);
    }
    cout << ans;
    return 0;
}