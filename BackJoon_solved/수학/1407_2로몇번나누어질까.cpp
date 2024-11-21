#include <iostream>
using namespace std;
using ll = long long;

ll cals(ll a ) {
    if (a == 0) return 0;
    else if (a == 1 ) return 1;
    else if (a%2 == 0) return a/2 + 2*cals(a/2);
    else return a/2 +1 + cals(a/2)*2;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll a , b; cin >> a >> b;
    cout << (cals(b) - cals(a-1));
    return 0;
}