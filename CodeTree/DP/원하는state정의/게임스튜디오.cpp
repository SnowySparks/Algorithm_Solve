#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_n = 1001;
const int inf = 1e9+7;
int n;

int dp[max_n][3][3]; //현재 i 번째 문자열을 보았을 때, 연속 b를 받은 홧수 (j), 현재까지 T 받은 수

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    dp[1][0][0] = 1; //G
    dp[1][1][0] = 1; //B
    dp[1][0][1] = 1; //T

    for (int i = 2; i <= n; ++i) {
        // 만약 G를 두게 되는 것이면 -> B 값은 무조건 0
        for (int t = 0; t < 3; ++t) {
            for (int b = 0; b < 3; ++b) {
                dp[i][0][t] += dp[i-1][b][t];
                dp[i][0][t] %= inf;
            }
        }

        // 만약 B를 두게 되는 것이면...
        for (int t = 0; t < 3; ++t) {
            for (int b = 1; b < 3; ++b) {
                dp[i][b][t] += dp[i-1][b-1][t];
                dp[i][b][t] %= inf;
            }
        }

        // 만약 T를 두게 되는 것이면
        for (int t = 1; t < 3; ++t) {
            for (int b = 0; b < 3; ++b) {
                dp[i][0][t] += dp[i-1][b][t-1];
                dp[i][0][t] %= inf;
            }
        }
    }
    int ans = 0;

    for (int t = 0; t < 3; ++t) {
        for (int b = 0; b < 3; ++b) {
            ans += dp[n][t][b];
            ans %= inf;
        }
    }
    cout << ans;
    return 0;
}