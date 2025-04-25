#include <iostream>
#include <cstring>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)
const int mv[3][2] = {
    {1, 0},
    {0, 1},
    {1, 1},
};
int n, m, t;
int dp[50][50][501]; //i, j위치에서 남은 시간이 t일 때, 최대한 처리할 수 있는 수
int workcnt[50][50];
int cost[50][50];
const int inf = 1e9;

int dfs(int r, int c, int leftTime) {
    if (r == n-1 && c == m-1) return 0;
    if (leftTime == 0) return -inf;
    int &res = dp[r][c][leftTime];
    if (res != -1) return res;
    res = -inf;

    for (auto [dr, dc] : mv) {
        int nr = r + dr, nc = c + dc;
        if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

        if (leftTime > 0) res = max(res, dfs(nr, nc, leftTime -1));
        if (leftTime > cost[nr][nc]) res = max(res, dfs(nr, nc, leftTime - cost[nr][nc] -1) + workcnt[nr][nc]);
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    f(i, 0, n) f(j, 0, m) cin>>workcnt[i][j];
    f(i, 0, n) f(j, 0, m) cin>>cost[i][j];
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0, t);
    return 0;
}