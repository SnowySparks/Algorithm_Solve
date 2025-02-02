#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int n, m;
const int inf = 1e9 + 7;
vector<pii> adj[1001]; // cost, next

int r1, r2, r3;
int dist1[1001], dist2[1001], dist3[1001];
int path1[1001], path2[1001], path3[1001];

void dijkstra(int start, int *dist, int *path) {
    for (int i = 1; i <= n; ++i) dist[i] = inf;
    dist[start] = 0;
    priority_queue<pii> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cost, loc] = pq.top(); pq.pop();
        cost = -cost;
        for (auto [addCost, nextNode] : adj[loc]) {
            int newCost = cost + addCost;
            if (newCost < dist[nextNode]) {
                dist[nextNode] = newCost;
                path[nextNode] = loc;
                pq.push({-newCost, nextNode});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> r1 >> r2 >> r3;

    dijkstra(r1, dist1, path1);
    dijkstra(r2, dist2, path2);
    dijkstra(r3, dist3, path3);

    int loc = 0;
    int minCost = inf;
    for (int i = 1; i <= n; ++i) {
        int totalCost = dist1[i] + dist2[i] + dist3[i];
        if (totalCost < minCost) {
            minCost = totalCost;
            loc = i;
        }
    }
    vector<pii> edges;
    for (int i = loc ; i != r1; i = path1[i]) {
        edges.push_back({path1[i], i});
    }
    for (int i = loc ; i != r2; i = path2[i]) {
        edges.push_back({path2[i], i});
    }
    for (int i = loc ; i != r3; i = path3[i]) {
        edges.push_back({path3[i], i});
    }

    cout << minCost <<' ' << edges.size() << '\n';
    for (auto [n1, n2] : edges) {
        cout << n1 << ' ' << n2 << '\n';
    }
    return 0;
}