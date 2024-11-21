#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll power(ll n, ll m){
    ll ret = 1;
    while(m){
        if(m & 1) ret = ret * n % mod;
        m/=2;
        n = n * n % mod;
    }
    return ret%mod;
}

int main(void) {
    int m; cin >> m;
    ll ans = 0;
    while (m--) {
        ll n, s; cin >> n >> s;
        ans = (ans + power(n,mod-2) * s) % mod;
    }
    cout << ans;
    return 0;
}