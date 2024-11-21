#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_n = 100;
const int OFFSET = 20;
int n, m;

int arr[101];
long long dp[101][41]; // i번째 숫자를 보았을 때, (j + OFFSET) 값의 개수

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    dp[0][OFFSET] = 1; //공백값
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <=n; ++i) {
        for (int j = -20; j <= 20; ++j) {
            if (j+OFFSET-arr[i] >= 0) dp[i][j+OFFSET] += dp[i-1][j+OFFSET-arr[i]];
            if (j+OFFSET+arr[i] <= 40)dp[i][j+OFFSET] += dp[i-1][j+OFFSET+arr[i]];
        }
    }
    // for (int i = 0; i <=n; ++i) {
    //     for (int j = -total; j <= total; ++j) {
    //         cout << dp[i][j + OFFSET] <<' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[n][m+OFFSET];
    return 0;
}