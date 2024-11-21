#include <iostream>
using namespace std;
using ll = long long;
using pl = pair<ll,ll>;
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
}
ll ccw(pl a, pl b, pl c) {
    return ccw(a.first,a.second,b.first,b.second,c.first,c.second);
}

int cw(pl a, pl b, pl c) {
    ll r = ccw(a,b,c);
    if (r > 0) return 1;
    else if (r < 0) return -1;
    else return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pl a1, a2, b1, b2;
    cin >> a1.first >> a1.second >> a2.first >> a2.second;
    cin >>b1.first >>b1.second >> b2.first >> b2.second;

    if (a1 > a2) swap(a1,a2);
    if (b1 > b2) swap(b1,b2);

    int c1 = cw(a1,a2,b1)*cw(a1,a2,b2);
    int c2 = cw(b1,b2,a1)*cw(b1,b2,a2);

    if (c1 <= 0 && c2 <=0) {
        if (c1 == 0 && c2 == 0) {
            if (b1 <= a2 && a1 <= b2) cout << 1;
            else cout << 0;
        }
        else cout << 1;
    }
    else cout << 0;
    return 0;
}