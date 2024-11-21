#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000009
long long dp[100001][3];

int main(void) {
    int N; cin >> N;
    dp[1][0] = 1; //1 = 1
    dp[2][1] = 1; //2 = 2
    dp[3][0] = 1; dp[3][1] = 1; dp[3][2] = 1;

    for (int i = 4 ; i <= 100000 ; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2])%mod;
        dp[i][1] = (dp[i-2][0] + dp[i-2][2])%mod;
        dp[i][2] = (dp[i-3][0] + dp[i-3][1])%mod;
    }
    int inp;
    while (N--) {
        cin >> inp;
        cout << (dp[inp][0] + dp[inp][1] + dp[inp][2])%mod <<'\n';
    }

}