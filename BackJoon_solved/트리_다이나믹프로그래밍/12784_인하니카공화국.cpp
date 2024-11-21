#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int _m = 1001;
const int inf = 1E9;
int N, M;
vector<pair<int,int> > gh[_m];
int dp[_m];

int dfs(int n, int p) {
    if (dp[n] != 0) return dp[n];
    int r = inf;
    int s = 0;
    for (pair<int, int> e : gh[n]) {
        if (e.first == p) r = e.second;
        else if (gh[e.first].size() == 1) s+=e.second;
        else s += dfs(e.first, n);
    }
    return dp[n] = min(r, s);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int a, b, cost;
    while(T--) {
        cin >> N >> M;
        for (int i = 0 ; i < M ; i++) {
            cin >> a >> b >> cost;
            gh[a].push_back({b,cost});
            gh[b].push_back({a,cost});
        }
        cout << dfs(1,0) << '\n';
        fill(dp, dp+N+1, 0);
        for (int i = 1 ; i <= N ; i++) gh[i].clear();
    }
    return 0;
}