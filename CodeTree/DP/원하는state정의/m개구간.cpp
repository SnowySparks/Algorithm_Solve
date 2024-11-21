#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
const int inf = 1e9 + 7;
int arr[501];
int dp[501][251]; //i번째 원소를 보았고, 사용한 구간은 j개인 경우 그 각각 그룹핑의 최대값
int seq[501][501]; // [i, j] -> 해당 구간에서 연속합 최대값 (i <= j 만 허용)
// 백준 2228에서도 동일한 문제임
int main(void) { 
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    //초기값 

    for (int i = 1; i <= n; ++i) {
        seq[i][i] = arr[i];
        for (int j = i+1; j <= n; ++j) {
            seq[i][j] = max(seq[i][j-1] + arr[j], arr[j]);
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <=m; ++j) dp[i][j] = -inf;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) dp[i][1] = max(dp[i-1][1] + arr[i], arr[i]);

    for (int j = 2; j <= m; ++j) {
        for (int i = (2*j - 1); i <= n; ++i) {
            for (int k = 0; k <= i-2; ++k) dp[i][j] = max(dp[i][j], dp[k][j-1] + seq[k+2][i]);
        }
    }
    int ans = -inf;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i][m]);
        // cout << dp[i][m] <<' ';
    }
    // cout << '\n';
    cout << ans;
    return 0;
}