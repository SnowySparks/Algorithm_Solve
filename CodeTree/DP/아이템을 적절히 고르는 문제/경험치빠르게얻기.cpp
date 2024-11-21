#include <iostream>
#include <cstring>
#include <algorithm>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;

int n, m;
int dp[10001]; // i시간이 걸릴 경우, 최대 경험치

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int e, t;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    f(i, 1, n+1) {
        cin >> e >> t;
        for(int j = 10000; j >= t; --j) {
            if (dp[j-t] != -1) dp[j] = max(dp[j], dp[j-t]+e);
        }
    }

    f(i, 0, 10001) {
        if (dp[i] >= m) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}