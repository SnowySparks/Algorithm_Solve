#include <iostream>
#include <vector>
#include <algorithm>
#define _max 1000001
using namespace std;

int dp[_max][2];
bool visited[_max];
vector<int> gh[_max];

void dfs(int root) {
    visited[root] = true;
    dp[root][0] = 0;
    dp[root][1] = 1;

    for (auto e : gh[root]) {
        if (visited[e]) continue;
        dfs(e);
        dp[root][0] += dp[e][1];
        dp[root][1] += min(dp[e][0] , dp[e][1]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    int a,b;
    for (int i = 1 ; i<= N ;i++) {dp[i][0] = -1; dp[i][1] = -1;}
    for (int i = 0 ; i < N -1; i++) {
        cin >> a >> b;
        gh[a].push_back(b);
        gh[b].push_back(a);
    }
    dfs(1);
    cout << min(dp[1][0],dp[1][1]); return 0;
}