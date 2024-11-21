#include <iostream>
using namespace std;
const long long mod = 1000000007;
using ll = long long;
ll dp[1000001];
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    dp[0] = 1; dp[1] = 2; dp[2] = 7;
    if (n <= 2) {
        cout << dp[n];
        return 0;
    }
    for (int i =3;i <= n; ++i) {
        dp[i] = (3*dp[i-1] + dp[i-2] - dp[i-3] + mod)%mod;
    }
    cout << dp[n];
    return 0;
}

// 원리
// dp[i] (i >= 3) 기준
// dp[i-1] 에서 채우는 경우의 수 2가지
// dp[i-2] 에서 채우는 경우의 수 3가지 (dp[i-1] 경우와 겹치지 않는)
// dp[k] (k <= i-3) 에처 채우는 경우의 수 : 2가지 (그 직전까지 경우 겹치지 않고)
// 따라서 다음과 같은 식 성립 : dp[i] = 2dp[i-1] + 3dp[i-2] + sum(dp[k]_ 0<=k<=i-3)
// 누적합을 이용하는 방법도 있음 
// 하지만 dp[n+1] - dp[n] 이식을 이용해서 위와 같은 코드가 나옴
