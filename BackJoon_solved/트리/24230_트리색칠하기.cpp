#include <iostream>
#include <vector>  
#include <algorithm>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
const int MAXN = 2e5 + 2;

int n;
int nodeColor[MAXN];
vector<int> adj[MAXN];
int ans = 0;

void dfs(int node, int pnode, int color) {
    for (int child : adj[node]) {
        if (child == pnode) continue;
        if (nodeColor[child] != color) ++ans;
        dfs(child, node, nodeColor[child]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int a, b;
    f(i, 1, n+1) cin >> nodeColor[i];
    f(i, 0, n-1) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans = (nodeColor[1] == 0 ? 0 : 1);
    dfs(1, -1, nodeColor[1]);
    cout << ans;
    return 0;
}