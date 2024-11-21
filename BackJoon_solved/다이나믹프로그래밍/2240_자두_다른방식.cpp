#include <iostream>
#include <cstring>
using namespace std;
int T, W;
int jadu[1001];
int dp[1001][31];
int dfs(int t, int move ) {
    int loc = (move % 2 == 0) ? 1 : 2;
    if (t == T) return (jadu[t] == loc ? 1 : 0);
    if (dp[t][move] != -1) return dp[t][move];
    dp[t][move] = 0;
    if (move < W) dp[t][move] += max(dfs(t+1, move+1), dfs(t+1, move))+(jadu[t] == loc ? 1 : 0);
    else dp[t][move] += dfs(t+1, move) + (jadu[t] == loc ? 1 : 0);
    return dp[t][move];
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T >> W;
    for (int i = 1 ; i <= T ; i ++) cin >> jadu[i];
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0);
    return 0;
}