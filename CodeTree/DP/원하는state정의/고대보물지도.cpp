#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_n = 1e5;
const long long inf = 1e18;
int n, k;
long long arr[max_n+1];
long long dp[max_n+1][11]; //i 번째 바라보았고 현재 j개 음수도 포함되어 있을때 그 연속 최대값
long long ans = - inf;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    // dp셋팅
    for (int i = 1; i <=n; ++i) fill(dp[i], dp[i]+11, -inf);
    dp[0][0] = 0; 
    // 음수 0개일 때
    for (int i = 1; i <=n; ++i) {
        if (arr[i] >= 0) dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
        ans = max(ans, dp[i][0]);
    }

    // 음수 1개 이상 K개이하연속일때 
    for (int j = 1; j <= k; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (arr[i] < 0 && dp[i-1][j-1] != inf) {
                dp[i][j] = max(dp[i-1][j-1] + arr[i], arr[i]);
            }
            if (arr[i] >= 0 && dp[i-1][j] != inf) dp[i][j] = max(dp[i-1][j] + arr[i], dp[i][j]);
            ans = max(ans, dp[i][j]);
        }
    }

    // for (int j = 0; j <= k; ++j) {
    //     for (int i = 1; i <= n; ++i) cout << dp[i][j] <<' ';
    //     cout << '\n';
    // }
    cout << ans;
    return 0;
}