#include <iostream>
#include <cstring>
#include <algorithm>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;

int n, m;
int dp[1001];// 1, 2, 5
int val[3] = {1, 2, 5};
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    dp[1] = 1; dp[2] = 2; dp[3] = 3; dp[4] = 5; dp[5] = 9;
    f(i, 6, n+1) {
        for (int &v : val) {
            dp[i] += dp[i-v];
            dp[i] %= 10007;
        }
    }
    cout << dp[n];
    return 0;
}