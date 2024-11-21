#include <iostream>
#include <algorithm>
#include <cstring>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
int n, m, dp[50][50], arr[50][50];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> n >> m;
    f(i, 0, n) f(j, 0, m) cin >> arr[i][j];
    memset(dp, -1, sizeof(dp)); // -1 구역 : 도달 못하는 공간
    dp[0][0] = 1;

    for (int sr = 1; sr < n; ++sr) {
        for (int sc = 1; sc < m; ++sc) {

            for (int i = 0; i < sr; ++i) {
                for (int j = 0; j < sc; ++j) {
                    if (arr[i][j] < arr[sr][sc] && dp[i][j] != -1) dp[sr][sc] = max(dp[sr][sc], dp[i][j] + 1);
                }
            }

        }
    }

    int ans = 0;
    f(i, 0, n) f(j, 0, m) ans = max(ans, dp[i][j]);
    // f(i, 0, n) {
    //     f(j, 0, m) cout << dp[i][j] <<' ';
    //     cout << '\n';
    // }
    cout << ans;
    return 0;
}