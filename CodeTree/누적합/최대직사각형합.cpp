#include <iostream>
#include <algorithm>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;

int n;
int arr[301][301];
int prefix[301];
int dp[301];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 1, n+1) f(j, 1, n+1) cin >> arr[i][j];
    // 세로방향 누적합
    f(c, 1, n+1) {
        f(r, 1, n+1) arr[r][c] += arr[r-1][c];
    }

    // f(i, 1, n+1) {
    //     f(j, 1, n+1) cout << arr[i][j] <<' ';
    //     cout << '\n';
    // }
    int ans = -1;
    // 행 범위 [cr, er] -> n^2 시간복잡도
    for (int er = 1; er <= n; ++er) {
        for (int cr = 1; cr <= er; ++cr) {
            f(i, 1, n+1) prefix[i] = arr[er][i] - arr[cr-1][i];
            // memset(dp, 0, sizeof(dp));
            f(i, 1, n+1) {
                dp[i] = max(prefix[i], dp[i-1]+prefix[i]);
            }
            ans = max(ans, *max_element(dp+1, dp+n+1));
        }
    }
    cout << ans;
}