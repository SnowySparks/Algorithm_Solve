#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int inf = 1E6;

const int mo[5][5] {
    {0, 2, 2, 2, 2},
    {inf, 1, 3, 4, 3},
    {inf, 3, 1, 3, 4},
    {inf, 4, 3, 1, 3},
    {inf, 3, 4, 3, 1}
};

int dp[100002][5][5];
int dt[100002];

int dfs(int l, int r, int loc) {
    if (dt[loc] == 0) return 0;
    int &ret = dp[loc][l][r];
    if (ret != -1) return ret;
    ret = min(dfs(dt[loc], r, loc+1)+ mo[l][dt[loc]], dfs(l, dt[loc], loc+1) + mo[r][dt[loc]]);
    return ret;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cnt = 0, tp;
    while(true) {
        cin >> dt[++cnt];
        if (dt[cnt] == 0) break;
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0,0,1);
}