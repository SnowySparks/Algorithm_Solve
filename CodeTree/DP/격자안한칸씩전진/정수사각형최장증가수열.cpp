#include <iostream>
#include <cstring>
using namespace std;
#define f(a, b, c) for(int a=b;a<c;++a)
int n;
int arr[500][500];
int dp[500][500];
int ans = 1;

int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(int r, int c) {
    int &res = dp[r][c];
    if (res != -1) return res;
    res = 1;
    for (auto &[dr, dc] : mv) {
        int nr = r + dr, nc = c + dc;
        if (nr < 0 || nr >= n || nc < 0 || nr >= n) continue;
        if (arr[nr][nc] > arr[r][c]) {
            res = max(res, dfs(nr, nc) + 1);
        }
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) f(j, 0, n) cin >> arr[i][j];
    memset(dp, -1, sizeof(dp));
    f(i, 0, n) f(j, 0, n) ans = max(ans, dfs(i, j));
    cout << ans;
}