#include <iostream>
#include <cstring>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
const int inf =1e9+7;
int n;
int arr[100][100];
int dp[100][100];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) f(j, 0, n) cin >> arr[i][j];
    dp[0][0] = arr[0][0];
    f(i, 1, n) {
        dp[i][0] = max(arr[i][0], dp[i-1][0]);
        dp[0][i] = max(arr[0][i], dp[0][i-1]);
    }

    f(i, 1, n) f(j, 1, n) {
        dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), arr[i][j]);
    }
    cout << dp[n-1][n-1];
    return 0;
}