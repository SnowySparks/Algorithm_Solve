#include <iostream>
#include <algorithm>
#include <queue>
#define f(a,b,c) for (int a = b; a < c; a++)
using namespace std;
using ll = long long;
const ll inf = 1E13;
const int mdt = 1E5+1;
ll dist[mdt];
vector<pair<int, int> > gh[mdt];
int x, z; //start , end;
int N, M;
void direk(int s, int l) {
    fill(dist,dist+N+1, inf);
    dist[s] = 0;
    priority_queue<pair<ll, int> > pq;
    pq.push({0,s});
    while(!pq.empty()) {
        ll cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (node == l) continue;
        if (dist[node] < cost) continue;
        for (auto e : gh[node]) {
            ll ncost = cost + e.second;
            if (dist[e.first] > ncost) {
                dist[e.first] = ncost;
                pq.push({-ncost,e.first});
            }
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int u, v, w;
    f(i,0,M) {
        cin >> u >> v >> w;
        gh[u].push_back({v,w});
    }
    int start, end, mid_d; cin >> start >> mid_d >> end;
    direk(start,-1);
    ll m1 = dist[mid_d];
    direk(mid_d,-1);
    m1 += dist[end];
    direk(start, mid_d);
    ll without = dist[end];
    cout << (m1 >= inf ? -1 : m1) << ' ';
    cout << (without >= inf ? -1 : without);
    return 0;
}