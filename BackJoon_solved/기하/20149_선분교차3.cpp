#include <iostream>
using namespace std;
using ll = long long;
using pl = pair<ll,ll>;
using d = long double;
ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
}
ll ccw(pl a, pl b, pl c) {
    return ccw(a.first,a.second,b.first,b.second,c.first,c.second);
}

int cw(pl a, pl b, pl c) {
    ll r = ccw(a,b,c);
    return (r > 0) ? 1 : (r < 0 ? -1 : 0);
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

    if (c1 <= 0 && c2 <= 0) {
        if (c1 == 0 && c2 == 0) {
            if (!(b1 <= a2 && a1 <= b2)) {cout << 0; return 0;}
            cout << "1\n";
            if (a1 == b2 && b1 <=a1) {
                cout << a1.first << ' ' << a1.second;
            }
            else if ( a2 == b1 && a1 <= b1) {
                cout << a2.first <<' ' << a2.second;
            }
            else if (a2 == b2 && cw(a1,b1,a2)!=0) {
                cout << a2.first <<' ' << a2.second;
            }
            else if (a1 == b1 && cw(a2,b2,a1)!=0) {
                cout << a1.first << ' ' << a1.second;
            }
        }
        else {
            cout << 1<<'\n';
            cout << fixed; cout.precision(10);
            d x1 = a1.first, y1 = a1.second, x2=a2.first, y2=a2.second;
            d x3 = b1.first, y3 = b1.second, x4=b2.first, y4=b2.second;
            d px = ((x1*y2 - y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4) - (y1-y2)*(x3-x4));
            d py = ((x1*y2 - y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4) - (y1-y2)*(x3-x4));
            cout << px << ' ' << py;
        }
    }
    else cout << 0;




    return 0;
}