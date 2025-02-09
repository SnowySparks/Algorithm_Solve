#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
const ll inf = 1e16;
int n, k;
struct info {
    //walk_time, walk_money, cycle_time, cycle_money
    int wt; ll wm;
    int ct; ll cm;
};
ll dp[100001];
ll tmp[100001];
info d[101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> d[i].wt >> d[i].wm >> d[i].ct >> d[i].cm;
    memset(tmp, -1, sizeof(tmp));
    dp[0] = 0;
    for (int idx = 1; idx <= n; ++idx) {
        memset(tmp, -1, sizeof(tmp));
        for (int t = k; t >= d[idx].ct; --t) {
            if (dp[t - d[idx].ct] != -1) tmp[t] = max(tmp[t], dp[t - d[idx].ct] + d[idx].cm );
        }
        for (int t = k; t >= d[idx].wt; --t) {
            if (dp[t - d[idx].wt] != -1) tmp[t] = max(tmp[t], dp[t - d[idx].wt] + d[idx].wm );
        }
        swap(dp, tmp);
    }
    ll ans = -inf;
    for (int i = 1; i <= k; ++i) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}