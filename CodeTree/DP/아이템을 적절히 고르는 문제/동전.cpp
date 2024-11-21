#include <iostream>
#include <vector>
using namespace std;
int dp[10001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int inf = 1e9;
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (int i = 1; i <= m; ++i) dp[i] = inf;
    for (int i = 0; i < n; ++i) cin >> coins[i];
    for (const int &coin : coins) {
        for (int i = coin; i <=m ; ++i) {
            dp[i] = min(dp[i], dp[i-coin] + 1);
        }
    }
    cout << (dp[m] == inf ? -1 : dp[m]);
    return 0;
}