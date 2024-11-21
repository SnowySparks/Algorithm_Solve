#include <iostream>
#include <vector>

#define f(a,b,c) for (int a =b; a<c;++a)
using namespace std;
int cnt = 0;
int n,root, q, p[50];
vector<int> adj[50];

void dfs(int node) {
    if (adj[node].empty()) {++cnt; return;}
    for (int e : adj[node]) dfs(e);
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i,0,n) {
        cin >> p[i];
        if (p[i]==-1) {root = i; p[i] = i;}
    }
    cin >> q;
    f(i,0,n) {
        if (i != q && i != p[i]) adj[p[i]].push_back(i);
    }
    
    if (q==root) {
        cout << 0; return 0;
    }
    dfs(root);
    cout << cnt;
    return 0;
}