#include <iostream>
using namespace std;
using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll k, p, n; cin >> k >> p >> n;
    ll mod = 1e9 + 7;
    ll res = k;
    ll mul = p;
    n*=10;

    while (n)
    {
        if (n&1) {
            res *= mul;
            res%=mod;
        }
        mul = mul * mul % mod;
        n>>=1;
    }
    cout << res;
    return 0;
}