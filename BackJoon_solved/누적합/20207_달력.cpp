#include <iostream>
using namespace std;
int dp[370];
int n;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        dp[a]++;
        dp[b+1]--;
    }
    for (int i = 1; i <= 366; ++i) dp[i] += dp[i-1]; 
    int l = 0, h = 0;
    int ans = 0;
    for (int i = 1; i <= 366; ++i) {
        if (dp[i-1] && !dp[i]) {
            ans += h*(i-l);
            h=-1;
        }
        else if (!dp[i-1] && dp[i] ) l = i;
        if (dp[i]) h = max(h, dp[i]);
    }
    cout << ans;
    return 0;
}