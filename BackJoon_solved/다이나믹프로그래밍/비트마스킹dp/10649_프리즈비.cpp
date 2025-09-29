#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Cow {
    ll height, weight, power;
};
ll inf = 1e18;
int n; ll h;
Cow cows[20];
ll dp[1 << 20];
ll total_height[1<<20];
ll total_weight[1<<20];


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> h;
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].height >> cows[i].weight >> cows[i].power;
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = inf;

    for (int state = 1; state < (1 << n); ++state) {
        for (int idx = 0; idx < n; ++idx) {
            if (state & (1 << idx) ) {
                int beforeState = state - (1 << idx);
                total_height[state] = total_height[beforeState] + cows[idx].height;
                total_weight[state] = total_weight[beforeState] + cows[idx].weight;

                dp[state] = max(dp[state], max( 
                    min( dp[beforeState] - cows[idx].weight, cows[idx].power ), min(cows[idx].power - total_weight[beforeState], dp[beforeState]) )
                );
            }
        }
    }

    ll ans = -1;
    for (int state = 0; state < (1 << n); ++state) {
        if (total_height[state] >= h) {
            ans = max(ans, dp[state]);
        }
    }
    if (ans == -1) cout << "Mark is too tall";
    else cout << ans;
    return 0;
}