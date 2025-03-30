#include <iostream>
#include <algorithm>
using namespace std;
#define f(a, b, c) for(int a = b; a < c; ++a)
const int inf = 1e9;
int dp[501][501], n, m;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
    cin >> n >> m;
    f(i, 1, n+1) f(j, 1, n+1) dp[i][j] = inf;
    int a, b; 
    f(i, 0, m) {
        cin >> a >> b;
        dp[a][b] = 1;
    }
    f(mid, 1, n+1) {
        f(st, 1, n+1) {
            f(en, 1, n+1) {
                dp[st][en] = min(dp[st][en], dp[st][mid] + dp[mid][en]);
            }
        }
    }
    int ans = 0;
    f(target, 1, n+1) {
        int cnt = 0;
        f(i, 1, n+1) {
            if (i == target) continue;
            if (dp[target][i] < inf || dp[i][target] < inf) ++cnt;
        }
        if (cnt == n-1) ans++;
    }
    cout << ans;
    return 0;
}