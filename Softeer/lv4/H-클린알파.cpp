#include <iostream>
using namespace std;
using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll p; int n; cin >> p >> n;
    ll mod = 1000000007;
    ll tmp;
    ll ans = 0;
    while (n--)
    {
        ans *= p;
        ans %= mod;
        cin >> tmp;
        ans += tmp;
        ans %= mod;
    }
    cout << ans;
    return 0;
}