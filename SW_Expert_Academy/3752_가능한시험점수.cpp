#include <iostream>
#include <cstring>
using namespace std;
const int inf = 100 * 100 + 1;
bool dp[inf];
#define f(a,b,c) for (int a=b;a<c;a++)

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int n, max_val = 0, coin;
    f(i, 1, t+1) {
        cin >> n;
        memset(dp, false, sizeof(dp));
        max_val = 0;
        dp[0] = true;
        // coin
        f(j, 1, n+1) {
            cin >> coin;
            max_val += coin;
            for (int k = max_val - coin; k >= 0; k--) if (dp[k]) dp[k+coin] = true;
        }
        int cnt = 0;
        f(k, 0, max_val + 1) if (dp[k]) cnt++;
        cout << '#'<<i<<' '<<cnt<<'\n';
    }
    return 0;
}