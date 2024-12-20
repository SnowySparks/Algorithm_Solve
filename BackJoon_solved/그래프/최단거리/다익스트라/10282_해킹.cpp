#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const int inf = 1e9 + 7;

int T; //test case
int n, d, c, cnt, max_dist;
vector<pair<int, int > > adj[10001]; // <cost, 다음 노드>
priority_queue<pair<int ,int> > pq; // <-거리, 노드>
int dist[10001];

void reset() {
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 1; i <= n; ++i) dist[i] = inf;
    dist[c] = 0;
    cnt = 0;
    max_dist = -1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> T;
    int cur_dist, node, a, b ,s;
    while (T--)
    {
        cin >> n >> d >> c;
        reset();
        for (int i = 0; i < d; ++i) {
            cin >> a >> b >> s;
            adj[b].push_back({s, a});
        }
        pq.push({0, c});

        while (!pq.empty())
        {
            tie(cur_dist, node) = pq.top(); pq.pop();
            cur_dist = -cur_dist;

            for (auto [cost, child] : adj[node]) {
                int added_cost = cost + cur_dist;
                if (dist[child] > added_cost) {
                    dist[child] = added_cost;
                    pq.push({-added_cost, child});
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (dist[i] != inf) {
                ++cnt;
                max_dist = max(max_dist, dist[i]);
            }
        }
        cout << cnt <<' ' << max_dist << '\n';
    }
    
    return 0;
}