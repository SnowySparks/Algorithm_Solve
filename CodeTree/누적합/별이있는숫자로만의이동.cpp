#include <iostream>
#include <cstring>
#define f(a, b, c) for (int a=b;a<c;++a)
using namespace std;
int n, k;
int dp[401][401];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    f(i, 1, n+1) {
        f(j,1,n+1) {
            cin >> dp[i][j];
        }
    }

    f(c, 1, n+1) {
        f(r, 1, n+1) {
            dp[r][c] += dp[r-1][c];
        }
    }

    int ans = 0;

    f(r, 1, n+1) {
        f(c, 1, n+1) {
            int min_c = max(1, c - k);
            int max_c = min(n, c + k);
            int tmp = 0;
            for (int lc = min_c; lc <= max_c; ++lc) {
                int radius = k - abs(c - lc);
                int minR = max(r - radius, 1);
                int maxR = min(r + radius, n);
                tmp += dp[maxR][lc] - dp[minR-1][lc];

            }
            ans = max(ans, tmp);
        }
    }
    cout << ans;
    return 0;
}