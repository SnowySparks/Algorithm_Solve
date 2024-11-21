#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int T, W;
int jadu[1001];
int dp[1001][31][2];
int dfs(int t, int left, int loc) {
    if (t == T) {
        if (jadu[t] == loc) return 1;
        else return 0;
    }
    if (dp[t][left][loc] != -1) return dp[t][left][loc];
    dp[t][left][loc] = 0;
    //left == 0 , 더이상 움직이지 못함
    if (left == 0) {
        dp[t][left][loc] += dfs(t+1, left, loc) + (jadu[t] == loc ? 1 : 0); 
    }
    else {
        dp[t][left][loc] += max(dfs(t+1, left-1, (loc == 2 ? 1 : 2)) , dfs(t+1, left, loc)) + (jadu[t] == loc ? 1 : 0);
    }
    return dp[t][left][loc];
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T >> W;
    for (int i = 1 ; i <= T ; i ++) cin >> jadu[i];
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,W,1);

}