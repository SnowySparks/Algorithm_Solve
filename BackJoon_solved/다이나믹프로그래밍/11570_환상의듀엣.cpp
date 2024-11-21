#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int music[2001];
int dp[2001][2001];
int N;

int dfs(int l, int r) {
    if (l == N || r == N) return 0;
    int &ret = dp[l][r];
    if (ret!= -1) return ret;
    int now = max(l,r)+1;
    int nl = (l == 0 ) ? 0 : abs(music[now] - music[l]);
    int nr = (r == 0 ) ? 0 : abs(music[now] - music[r]);
    return dp[l][r] = min(dfs(now,r)+nl, dfs(l,now)+nr);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1 ; i <= N ; i++) cin >> music[i];
    memset(dp,0x7f,sizeof(dp));
    dp[1][0] = 0; dp[0][1] =0;

    for (int l = 0 ; l <= N ; l++) {
        for (int r = 0 ; r <= N ; r++) {
            if (l == r) continue;
            int nxt = max(l,r)+1;
            
            dp[l][nxt] = min(dp[l][nxt], dp[l][r] + abs( r == 0? 0 : abs(music[nxt] -music[r])));
            dp[nxt][r] = min(dp[nxt][r], dp[l][r] + abs( l == 0? 0 : abs(music[nxt] -music[l])));
        }
    }
    int ans = INT32_MAX;
    for (int i = 0; i < N ;i++) {
        ans = min(ans, dp[N][i]);
        ans = min(ans, dp[i][N]);
    }  
    cout << ans;

}