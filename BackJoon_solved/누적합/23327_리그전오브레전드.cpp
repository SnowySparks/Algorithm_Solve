#include <iostream>
#include <vector>
#define f(a,b,c) for (int a=b; a<=c;a++)
using namespace std;
using ll = long long;

ll dp[100001][2];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    f(i,1,n) {
        cin >> dp[i][0];
        dp[i][0] += dp[i-1][0];
        if (i > 1) {
            dp[i][1] = dp[i-1][1] + dp[i-1][0]*(dp[i][0] - dp[i-1][0]);
        }
    }
    int l, r;
    f(i,1,q) {
        cin >> l >> r;
        cout << (dp[r][1] - (dp[l-1][0] * (dp[r][0] - dp[l-1][0])) - dp[l-1][1]) <<'\n';
    }
    return 0;
}