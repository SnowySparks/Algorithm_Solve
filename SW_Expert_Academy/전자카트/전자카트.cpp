#include <iostream>
#include <cstring>
#define f(a, b, c) for (int a=b; a<c;++a)
using namespace std;
#define M 100000000
int n;
int arr[10][10];
int dp[10][1<<10];

int dfs(int now, int state) {
    if (state == (1<<n) -1) {
        if (now == 0) return M;
        return arr[now][0];
    }
    int &res = dp[now][state];
    if (res != -1) return res;
    res = M;
    f(idx, 0, n) {
        if ( (state & (1<<idx) )|| (now == idx) ) continue;
        res = min(res, dfs(idx, state | (1<<idx)) + arr[now][idx]);
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    f(tc, 1, T+1) {
        cin >> n;
        f(i, 0, n) f(j, 0, n) cin >> arr[i][j];
        memset(dp, -1, sizeof(dp));
        cout << '#' << tc <<' ' << dfs(0, 1) <<'\n'; 
    }
    return 0;
}