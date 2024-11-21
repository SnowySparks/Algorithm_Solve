#include <iostream>
#include <algorithm>
#include <queue>
#define f(a,b,c) for (int a = b; a < c; a++)
using namespace std;
using ll = long long;
const ll inf = 1E13;
const int mdt = 1E5+1;
ll fromto[mdt];
ll endto[mdt];
vector<pair<int, int> > gh[mdt];
int x, z; //start , end;
int N, M;
void direk(int s, ll* arr) {
    arr[s] = 0;
    priority_queue<pair<ll, int> > pq;
    pq.push({0,s});
    while(!pq.empty()) {
        ll cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (arr[node] < cost) continue;
        for (auto e : gh[node]) {
            ll ncost = cost + e.second;
            if (arr[e.first] > ncost) {
                arr[e.first] = ncost;
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
        gh[v].push_back({u,w});
    }
    cin >> x >> z;
    int p; cin >> p;
    vector<int> md(p);
    f(i, 0, p) cin >> md[i];
    fill(fromto,fromto+mdt,inf);
    fill(endto, endto+mdt,inf);
    direk(x,fromto);
    direk(z,endto);
    ll ans = inf;
    f(i,0,p) ans = min(ans , fromto[md[i]] + endto[md[i]]);
    cout << (ans >= inf ? -1 : ans);
    return 0;
}