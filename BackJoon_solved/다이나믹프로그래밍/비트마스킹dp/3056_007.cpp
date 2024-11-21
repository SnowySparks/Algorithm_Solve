#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
double dt[20][20];
double dp[1 << 20];

double dfs(int cur, int state) {
    if (state == (1<<N )-1) return 1;
    double &ret = dp[state];
    if (ret != 0) return ret;
    ret = 0;
    for (int i = 0; i < N; i++) {
        if (state & (1 << i)) continue;
        ret = max(ret , dfs(cur+1, state|(1<<i)) * dt[cur][i]/100.0);
    }
    return ret;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> dt[i][j];
    }
    cout << fixed;
    cout.precision(6);
    cout << dfs(0, 0)*100; return 0;
}