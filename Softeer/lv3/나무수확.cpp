#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)
const int inf = 1e3+1;
int n;
int arr[inf][inf];
int dp[inf][inf][2];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 1, n+1) {
        f(j, 1, n + 1) {
            cin >> arr[i][j];
        }
    }

    f(i, 1, n+1) {
        f(j, 1, n+1) {
            dp[i][j][0] = max(dp[i][j-1][0] , dp[i-1][j][0]) + arr[i][j];
            dp[i][j][1] = max(dp[i][j-1][0] , dp[i-1][j][0]) + 2*arr[i][j];
            dp[i][j][1] = max(dp[i][j][1], max(dp[i][j-1][1] , dp[i-1][j][1]) + arr[i][j]);
        }
    }
    cout << dp[n][n][1];
    return 0;
}