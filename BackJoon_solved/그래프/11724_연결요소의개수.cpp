#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[1001] ; 
vector<int> dt[1001];

void dfs(int n) {
    if (visited[n]) return;
    visited[n] = true;

    if (dt[n].size() > 0) {
        for (auto e : dt[n]) {
            if (!visited[e]) {
                dfs(e);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m; cin >> n >> m ;

    int a,b,ans=0;
    while (m--) {
        cin >> a >> b;
        dt[a].push_back(b);
        dt[b].push_back(a);
    }

    for (int i = 1 ; i <= n ; i++) {
        if (!visited[i]) ans++;
        dfs(i);
    }
    cout << ans;
    return 0;
}