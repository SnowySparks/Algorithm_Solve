#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n, k;
const int inf = 1e9;
vector<pair<int ,int>> adj[1002]; // cost, next

struct io {
    int loc, cost, leftMove;
    bool operator<(const io &other) const {
        return cost < other.cost;
    }
    bool operator>(const io &other) const {
        return cost > other.cost;
    }
};
int dist[1002];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> k;
    int u, v, w;
    while (k--)
    {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    priority_queue<io,vector<io>, greater<io> > q;
    for (int i = 1; i <= n+1; ++i) dist[i] = inf; 
    q.push({0, 0, 100});

    while (!q.empty())
    {
        auto [loc, cost, leftMove] = q.top();
        q.pop();

        for (auto &[weight, nextNode] : adj[loc]) {
            if (weight > 100) continue; // 애초에 못감
            if (leftMove >= weight) {
                int newCost = cost + weight;
                if (dist[nextNode] > newCost) {
                    dist[nextNode] = newCost;
                    q.push({nextNode, newCost, leftMove-weight});
                }
            }
            else {
                int newCost = cost + weight + 5;
                if (dist[nextNode] > newCost) {
                    dist[nextNode] = newCost;
                    q.push({nextNode, newCost, 100-weight});
                }                
            }
        }
    }
    // for (int i = 1; i <= n+1; ++i) {
    //     cout << i << ':' << dist[i] << '\n';
    // }
    cout << (dist[n+1] == inf ? 0 : dist[n+1]);
    return 0;
}