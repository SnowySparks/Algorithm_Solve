#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
int n, first_loc;
int loc[1001]; // 좌표 위치
ll cost[1001]; // 코스트
ll costSum[1001]; // 코스트 누적합
ll dp[1001][1001][2]; // [구간 l, r] 처리, 현재 위치 (0 : l / 1 : r)

ll dfs(int l, int r, int flag) {
    if (l == 1 && r == n) return 0;
    ll &res = dp[l][r][flag];
    if (res != -1) return res;
    ll leftOn = costSum[n] - costSum[r] + costSum[l-1];
    int nowLoc = flag == 0 ? l : r; // 현재 위치
    if (l-1 >= 1) {
        ll cal = dfs(l-1,r, 0) + leftOn*(loc[nowLoc] - loc[l-1]);
        if (res == -1 || res > cal) res = cal;
    }
    if (r+1 <= n) {
        ll cal = dfs(l,r+1,1) + leftOn*(loc[r+1] - loc[nowLoc]);
        if (res == -1 || res > cal) res = cal;
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> first_loc;
    for (int i =1; i <=n; ++i) cin >> loc[i] >> cost[i];
    for (int i =1; i <=n; ++i) costSum[i] = costSum[i-1] + cost[i];
    memset(dp, -1, sizeof(dp));
    cout << dfs(first_loc,first_loc,0);
    return 0;
}