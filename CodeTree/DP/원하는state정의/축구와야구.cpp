#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
const int inf = 1e9 + 7;
int s[1001];
int b[1001];
int n;
int dp[1001][12][10]; //현재 i번째, j축구, I야구며

int dfs(int idx, int sc, int bc) {
    if (idx == n) return 0;
    if(sc == 11 && bc == 9) return 0;
    if ((n - idx) < 11 - sc && (n - idx) < 9 - bc) return -inf;

    int &res = dp[idx][sc][bc];
    if (res != -1) return res;
    res = 0;

    if (sc + 1 <= 11) res = max(res, dfs(idx+1, sc+1, bc) + s[idx+1]);
    if (bc + 1 <= 9) res = max(res, dfs(idx+1,sc,bc+1) + b[idx+1]);
    res = max(res, dfs(idx+1, sc, bc));
    return res;

}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 1, n+1) cin >> s[i] >> b[i];
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0, 0);
    return 0;
}