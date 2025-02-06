#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int arr[16];
long long dp[16][1<<16];

long long dfs(int idx, int state) {
    if (state == ( (1 << n) - 1)) {
        return 1;
    }
    long long &res = dp[idx][state];
    if (res != -1 ) return res;
    res = 0;
    for (int i = 0; i < n; ++i) {
        if (state & (1 << i)) continue;
        if (abs(arr[idx] - arr[i]) > k) {
            res += dfs(i, state | (1 << i));
        }
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dfs(i, (1 << i));
    }
    cout << ans;
    return 0;
}