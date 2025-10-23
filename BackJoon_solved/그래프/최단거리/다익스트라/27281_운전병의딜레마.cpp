#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int MAXN = 5e4 + 1;
const ll INF = 1e18 + 7;
ll dist[MAXN] = {0, };
int N, M; ll T;

struct Edge {
    int nxt, t, s;
    Edge(int nxt, int t, int s) : nxt(nxt), t(t), s(s) {}
};

vector<Edge> adj[MAXN];

ll dijkstra(ll max_s) {
    for (int i = 1; i <= N; ++i) dist[i] = INF;
    dist[1] = 0;

    priority_queue<pli, vector<pli>, greater<pli> > pq;

    pq.push({0, 1});

    while (!pq.empty())
    {
        int loc = pq.top().second; ll t = pq.top().first;
        pq.pop();

        if (t > dist[loc]) continue;
        
        for (Edge &node : adj[loc]) {
            ll new_t = t + node.t + max(0LL, 1LL*node.s - max_s);
            int nxt = node.nxt;
            if (new_t < dist[nxt] && new_t <= T) {
                dist[nxt] = new_t;
                pq.push({new_t, nxt});
            }
        }
    }
    if (dist[N] > T) return -1;
    return dist[N];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> T;
    int u, v, t, s;
    ll l = 0, r = 0;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> t >> s;
        r = max(r, 1LL * s);
        adj[u].push_back(Edge(v, t, s));
        adj[v].push_back(Edge(u, t, s));
    }

    ll ans = INF;

    while (l <= r) {
        ll mid = (l + r) / 2;
        ll res = dijkstra(mid);

        if (res == -1) {
            l = mid + 1;
            continue;
        }
        else {
            ans = min(ans,  mid);
            r = mid - 1;
        }
    }

    cout << (ans >= INF ? -1 : ans);
    return 0;
}