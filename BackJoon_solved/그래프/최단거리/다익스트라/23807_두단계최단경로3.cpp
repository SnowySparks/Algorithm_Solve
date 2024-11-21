#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define f(a,b,c) for(int a = b; a < c; a++)
using ll = long long;
const int mt = 1E5+1;
const ll inf = 1E13;
int N, M, P;
vector<pair<int, int> > gh[mt];
ll dist[100][mt];
void direk(int s, ll* arr) {
    arr[s] = 0;
    priority_queue<pair<ll, int> > pq;
    pq.push({0,s});
    while(!pq.empty()) {
        ll cost = -pq.top().first;int node = pq.top().second;pq.pop();
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
int st, en;
int seq[3];
ll tdist(int first, int second, int third , const vector<int> &lst) {
    ll res=0;
    res += dist[first][st] + dist[first][lst[second]];
    res+= dist[second][lst[third]];
    res += dist[third][en];
    return res;
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
    cin >> st>> en;
    cin >> P; vector<int> lst(P);
    f(i, 0, P) cin >> lst[i];
    f(i, 0 ,P) {fill(dist[i], dist[i]+N+1, inf); direk(lst[i],dist[i]);}
    ll ans = inf;
    f(i,0,P-2) f(k,i+1,P-1) f(t, k+1, P) {
        seq[0]=i; seq[1]=k; seq[2]=t;
        do {
            ans = min(ans, tdist(seq[0],seq[1],seq[2],lst));
        } while(next_permutation(seq,seq+3));
    }
    cout << (ans >= inf ? -1 : ans); return 0;
}