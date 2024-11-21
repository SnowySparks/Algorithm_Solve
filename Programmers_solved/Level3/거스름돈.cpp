#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define div 1000000007;

int solution(int n, vector<int> money) {
    vector<long long> dp(n+1);
    fill(dp.begin(),dp.end(),0);
    dp[0] = 1; // 정확히 동전 그 자체를 사용하는 경우를 저장하는 곳

    for (auto e : money) {
        //먼저 각각의 동전의 대한 루프,
        for (int j = e ; j <= n ; j++) {
            // i - e원의 경우의 수를 그대로 계승
            dp[j] += dp[j - e];
            dp[j] %= div;
        }
    }
    return dp[n]%div;

}
