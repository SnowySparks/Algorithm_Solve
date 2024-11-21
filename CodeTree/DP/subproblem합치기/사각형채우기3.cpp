#include <iostream>
#define f(a, b, c) for (int a=b;a<c;++a)
using namespace std;
using ll = long long;
const ll mod = 1e9+7;

ll dp[1001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    dp[0] = 1; dp[1] = 2; dp[2] = 7;
    f(i, 3, n+1) dp[i] = (3 * dp[i-1] + dp[i-2] - dp[i-3] + mod)%mod;
    cout << dp[n];
    return 0;
}