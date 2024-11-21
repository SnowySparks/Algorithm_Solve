#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000009
long long dp[1001][1001]; //number , 숫자 n개 사용

int main(void) {
    dp[1][1] = 1; dp[2][1] = 1; dp[2][2] = 1; dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;
    for (int i = 3; i <= 1000; i++) {
        for (int j = 2; j <= i ;j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1])%mod;
        }
    }
    int T; cin >> T;
    int a,b;
    long long ans;
    while (T--) {
        cin >> a>> b;
        ans = 0;
        for (int i = 1 ; i <=b; i++) {
            ans+=dp[a][i];
        }
        cout <<ans%mod << endl;
    }

}