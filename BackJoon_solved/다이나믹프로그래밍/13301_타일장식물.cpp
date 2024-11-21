#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[81];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    dp[1] = 1; dp[2] =2;
    dp[0] = 1;
    for (int i = 1 ; i <= N ; i++) dp[i]= dp[i-1] + dp[i-2];

    cout << 2* (dp[N] + dp[N-1]);
    return 0;
}