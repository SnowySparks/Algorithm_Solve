#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[50001];

int main(void) {
    int N; cin >> N;
    dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for (int i =4 ; i <= 50000; i++) {
        dp[i] = 1 << 30;
        for (int j = 1; j*j <= i ; j++) {
            dp[i] = min (dp[i], dp[i - j*j]+1);
        }
    }
    cout << dp[N];
    return 0;
}