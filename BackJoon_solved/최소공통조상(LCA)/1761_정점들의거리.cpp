#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, max_depth;
const int mn = 4E4+1;

vector<pair<int,int> > adj[mn];
int lv[mn];
int p[mn][16];
int dist[mn];

void dfs(int u, int pu, int df, int de = 0) {
    lv[u] = df;
    p[u][0] = pu;
    dist[u] = de;
    for (int i = 1; i <= max_depth; i++) p[u][i] = p[p[u][i-1]][i-1];
    for (pair<int,int> e : adj[u]) {
        if (e.first == pu) continue;
        dfs(e.first,u,df+1,de+e.second);
    }
}

int lca(int u, int v) {
    if (lv[u] < lv[v]) swap(u,v);
    if (lv[u] != lv[v]) {
        int dif = lv[u] - lv[v];
        for (int i = 0 ; dif ; i++) {
            if (dif & 1) u = p[u][i];
            dif>>=1;
        }
    }
    if (u == v ) return u;
    for (int i = max_depth ; i >=0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N; max_depth = int(log2(N));
    for (int i = 0 ; i < N-1; i++) {
        int u, v, d; cin >> u >> v >> d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    dfs(1,0,1);
    int m; cin >> m;

    while(m--) {
        int a,b; cin >> a >> b;
        int loc = lca(a,b);
        cout << dist[a] + dist[b] - 2*dist[loc] <<'\n';
    }

    return 0;
}