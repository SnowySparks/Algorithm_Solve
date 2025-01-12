#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1e3+1;
using pii = pair<int ,int>;
vector<pii> adj[MAXN]; // <cost, next>
bool isConnect[MAXN];
int n, k;
vector<pii> tree[MAXN]; // tree 입력 전용, <cost, next>
int totalCost = 0;
int maxNode = 0;
int maxCost = 0;

void dfs(int node, int pnode, int preCost) {
    for (auto [cost, nextNode] : tree[node]) {
        if (nextNode == pnode) continue;
        if (maxCost < cost + preCost) {
            maxCost = cost + preCost;
            maxNode = nextNode;
        }
        dfs(nextNode, node, cost + preCost);
    }
}
struct edge {
    int fr, to, cost;
    bool operator<(const edge &other) const {
        return cost < other.cost;
    }
    bool operator>(const edge &other) const {
        return cost > other.cost;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> k;
    int a, b, c;


    for (int i = 0;i < k; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    // Prim Algorithm 이용
    priority_queue<edge, vector<edge>, greater<edge> > pq;
    pq.push({-1, 0, 0});
    while (!pq.empty()) {
        auto [fr, to, cost] = pq.top(); pq.pop();

        if (isConnect[to]) continue;
        if (fr >= 0) {
            tree[fr].push_back({cost, to});
            tree[to].push_back({cost, fr});
        }
        totalCost += cost;
        isConnect[to] = true;
        for (pii edge : adj[to]) {
            pq.push({to, edge.second, edge.first});
        }
    }
    cout << totalCost << '\n';

    // 트리 지름 구하기
    dfs(0, -1, 0);
    maxCost = 0;
    dfs(maxNode, -1, 0);
    cout << maxCost << '\n';
    return 0;
}