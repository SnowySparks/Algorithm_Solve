#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
using ll = long long;
#define f(a,b,c) for(int a= b; a<c;a++)
int N, M;
int p[50001];
bool v[50001];
int parent(int a) {
    if (p[a] == a) return a;
    return p[a] = parent(p[a]);
}

bool isunion(int a, int b) {
    int pa = parent(a), pb = parent(b);
    if (pa == pb) return false;
    p[max(pa,pb)] = min(pa,pb);
    return true;
}

ll ans = 0;


vector<pair<int, pair<int, int> > > dt;
vector<pair<int ,int> >adj[50001];


ll dfs(int s) {
    v[s] = true;
    if (adj[s].size() == 0) return 0;
    ll cost = 0;
    for (auto e : adj[s]) {
        if (v[e.first]) continue;
        cost =max(cost, dfs(e.first) + e.second);
    }
    return cost;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    f(i,1,N+1) p[i]=i;
    f(i,0,M) {
        int a,b,c; cin >> a >>b >>c;
        dt.push_back({c,{a,b}});
    }
    int start; cin >> start;
    sort(dt.begin(),dt.end(),greater<>());
    for (auto e : dt) {
        int c = e.first;
        int a = e.second.first, b = e.second.second;

        if (isunion(a,b)) {
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
            ans+= c;
        }
    }
    cout << ans*2 - dfs(start);

}