#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int dv = 1000000009;

long long dp[1001][1001]; // number , 사용수 개수

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    dp[1][1] = 1; dp[2][1] = 1; dp[2][2] = 1; dp[3][1] = 1;
    for (int i = 3 ; i <= 1000 ; i++) {
        for (int j = 2 ; j <= i ; j++) {
            dp[i][j] = (dp[i-3][j-1] + dp[i-2][j-1] + dp[i-1][j-1]) % dv;
        }
    }
    int n, m;
    while(T--) {
        cin >> n >> m;
        cout << dp[n][m] << '\n';

    }return 0;
}