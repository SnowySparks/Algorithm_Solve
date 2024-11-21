#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, max_depth;
const int mn = 1E5+1;

vector<int> adj[mn];
int p[mn][17];
int lv[mn];

bool cmp(int a, int b) {
    return lv[a] > lv[b];
}

void dfs(int u, int pr, int df) {
    lv[u] = df; p[u][0] = pr;
    for (int i = 1 ; i <= max_depth ; i++) p[u][i] = p[p[u][i-1]][i-1];
    for (int e : adj[u]) {
        if (e == pr) continue;
        dfs(e,u,df+1);
    }
}

int lca(int a, int b) {
    if (a == 1|| b== 1) return 1;
    if (lv[a] < lv[b]) swap(a,b);

    int dif = lv[a] - lv[b];
    for (int i = 0; dif ; i++) {
        if (dif & 1) a= p[a][i];
        dif >>=1;
    }
    int ret = a;
    if (a!=b) {
        for (int i = max_depth ; i>=0;i--){
            if (p[a][i] != p[b][i]) {
                a = p[a][i];
                b = p[b][i];
            }
            ret = p[a][i];
        }
    }
    return ret;
    
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N; max_depth = int(log2(N));

    for (int i = 0 ; i < N-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,1);
    int m; cin >> m;
    int lst[3];
    while (m--) {
        int r, u, v; cin >> r >> u >> v;
        lst[0] = lca(r,v);
        lst[1] = lca(r,u);
        lst[2] = lca(u,v);
        sort(lst,lst+3,cmp);
        cout << () <<'\n';

    }
    return 0;
}