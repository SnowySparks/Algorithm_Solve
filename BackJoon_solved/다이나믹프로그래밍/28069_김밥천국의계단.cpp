#include <iostream>
#include <vector>
using namespace std;
int n, k;
const int inf = 1e9;
int main(void) {
    cin >> n >> k;
    vector<int> dp(n+1, inf);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        dp[i+1] = min(dp[i+1], dp[i] + 1);
        if (i + i/2 <= n) {
            dp[i + i/2] = min(dp[i + i/2], dp[i] + 1);
        }
    }

    if (dp[n] <= k) cout << "minigimbob";
    else cout << "water";

    return 0;
}