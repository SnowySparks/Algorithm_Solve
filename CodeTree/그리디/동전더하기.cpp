#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    f(i, 0, n) cin >> coins[i];
    int ans = 0;
    for (int i = n-1; i >= 0; --i) {
        int coin = coins[i];
        ans += (k/coin);
        k%=coin;
    }
    cout << ans;
    return 0;
}