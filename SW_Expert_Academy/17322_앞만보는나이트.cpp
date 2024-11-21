#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll fact(int to, int from = 1) {
    ll res = 1;
    for (int i = from; i <= to; i++) {
        res = (res * i) % mod;
    }
    return res;
}

ll pow (ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int i = 1 ; i <= t ; ++ i) {
        ll A, B; cin >> A >> B;
        if ((2*A-B)%3 || (2*B-A)%3 || (2*A - B) < 0 || (2*B - A) < 0) {
            cout << '#' << i <<' '<< 0 << '\n';
            continue;
        }
        int a = (2*B-A)/3 , b = (2*A-B)/3;
        ll r1 = fact(a+b,max(a,b)+1);
        ll r2 = fact(min(a,b),1);

        cout << '#' << i <<' '<< (r1 * pow(r2,mod-2)) % mod << '\n';
    }

    return 0;

}