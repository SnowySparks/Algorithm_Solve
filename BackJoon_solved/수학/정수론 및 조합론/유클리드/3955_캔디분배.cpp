#include <iostream>
#include <cstring>
#include "stdlib.h"
using namespace std;
typedef long long ll;
const int INF = 1'000'000'000;

struct EEA {
    ll gcd, x, y;
};

EEA extended_euclid(ll a, ll b) {

    ll aa = abs(a), bb = abs(b);

    ll x_old = 1, y_old = 0, r_old = aa;
    ll x = 0, y = 1, r = bb;
    ll x_t, y_t, r_t, q;

    while (r)
    {
        q = r_old / r;
        x_t = x_old - x * q;
        y_t = y_old - y * q;
        r_t = r_old - r * q;

        x_old = x;
        y_old = y;
        r_old = r;

        x = x_t;
        y = y_t;
        r = r_t;
    }

    if (a < 0) x_old = -x_old;
    if (b < 0) y_old = -y_old;
    
    return {r_old, x_old, y_old};

}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int q; cin >> q;
    ll k, c;
    while (q--)
    {
        cin >> k >> c;

        if (c == 1) {
            if (k + 1 > INF) cout << "IMPOSSIBLE\n";
            else cout << (k + 1) << '\n';
            continue;
        }

        if (k == 1) {
            cout << 1 << '\n';
            continue;
        }

        EEA res = extended_euclid(-k, c);

        ll gcd = res.gcd;
        ll minus_xk = res.x;
        ll yc = res.y;

        if (gcd != 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        yc = ( (yc % k) + k ) % k;

        if (yc > INF) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << yc << '\n';
        
    }
    

    return 0;
}