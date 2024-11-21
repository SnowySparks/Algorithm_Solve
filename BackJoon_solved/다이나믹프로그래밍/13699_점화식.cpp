#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[36];

int main(void) {
    int N; cin >> N;
    dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 5;
    for (int i = 4 ; i <= N ; i++) {
        for (int k = 0 ; k < i/2 ; k++) {
            dp[i]+= dp[k]*dp[i-1-k]*2;
        }
        if (i%2 == 1) {
            dp[i]+= dp[i/2]*dp[i/2];
        }
    }
    cout << dp[N]; return 0;
}