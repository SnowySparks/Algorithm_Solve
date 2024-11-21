#include <iostream>
using namespace std;
int dp[8][8]; // nCr

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cout>>fixed; cout.precision(9);
    int T,n,tmp; cin >> T;
    for (int i = 0; i < 8; i++) dp[i][0] = 1;
    for (int i = 1 ; i < 8; i++) {
        for (int j = 1 ; j <= i ; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    for (int tc = 1; tc <= T; tc++) {
        double l = 0; cin >> n;
        for (int i = 0; i < n; i++) {cin >> tmp; l += tmp;}
        double p = 0;
        for (int i = 1 ;)

    }

}