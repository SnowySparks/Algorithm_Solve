#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
int n, k;
pii loc[502];
int totalDist = 0;
int dp[502][502]; // i인덱스 위치포인트까지, 총 j개 스킵
const int INF = 1e9 + 7;

int calDist(const pii &a, const pii &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int calDist(int a, int b) {
    return calDist(loc[a], loc[b]);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> loc[i].first >> loc[i].second;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) dp[i][j] = INF;
    }
    dp[1][0] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int h = 0; h <= j; ++h) {
                if (i-h-1 < 1) continue;
                dp[i][j] = min(dp[i][j], dp[i-h-1][j-h] + calDist(i, i-h-1));
            }

        }
    }
    int ans = INF;
    for (int i = 0; i <= k; ++i) ans = min(ans,dp[n][i]);
    cout << ans;
    return 0;
}