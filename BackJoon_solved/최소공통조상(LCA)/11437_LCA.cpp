#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 50001;
int N, max_depth;
vector<int> adj[maxn];
int lv[maxn];
int p[maxn][17];

void dfs(int u, int pr, int depth) {
    lv[u] = depth;
    p[u][0] = pr;
    for (int i = 1; i <= max_depth; i++) {
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v == pr) continue;
        dfs(v, u, depth + 1);
    }
}

int lca(int a, int b) {
    //root node == 1 set
    if (a == 1 || b == 1) return 1;
    if (lv[a] < lv[b]) swap(a,b);

    int lvdiff = lv[a] - lv[b];
    for (int i = 0 ; lvdiff; i++) {
        if (lvdiff & 1) a = p[a][i];
        lvdiff >>=1;
    }
    int ret = a;
    if (a != b) {
        for (int i = max_depth; i >=0; i--) {
            if (p[a][i]!=p[b][i]){
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
    cin >> N; max_depth = int(floor(log2(N)));
    for (int i = 1; i <= N-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,1);
    int m; cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u,v) <<'\n';
    }
    return 0;
}