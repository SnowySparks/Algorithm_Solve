#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_n = 1001;

// 현재
int arr[max_n]; // 
int dp[max_n][4]; // dp[i][j], 현재 i번계단 까지 탐색했다고 가정하고, 1계단은 j번 밟았는 상태일때 최대값
// 단 가능해야 할 것
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    dp[0][0] = 0;
    for (int i = 1; i <=n; ++i) cin >>arr[i];

    // 일단 오직 2계단만 밟았다고 가정
    for (int i = 2; i <= n; i+=2) {
        dp[i][0] = dp[i-2][0] + arr[i];
    }

    // 한 계단 밟는걸 설정
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-2][j]);
            if (dp[i][j] != -1) dp[i][j] += arr[i];
        }
    }
    cout << *max_element(dp[n], dp[n]+4);
    return 0;
}