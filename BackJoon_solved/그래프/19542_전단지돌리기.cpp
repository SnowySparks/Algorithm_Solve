#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5+1;
int n, s, d;
vector<int> adj[N];
int leftDepth[N];
int ans = 0;

void dfs(int node, int pnode) {
    for (int child : adj[node] ) {
        if (child == pnode) continue;
        dfs(child, node);
        leftDepth[node] = max(leftDepth[node], leftDepth[child]+1);
        if (leftDepth[child] >= d) ans += 2;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("in.txt","r",stdin);
    cin >> n >> s >> d;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(s,-1);
    cout << ans;
    return 0;   
}