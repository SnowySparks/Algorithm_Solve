#include <iostream>
using namespace std;
using ll = long long;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int i = 1 ; i <= t ; ++ i) {
        ll A, B; cin >> A >> B;
        ll diff = B - A;

        ll ans = 0;
        if (diff == 0) ans = 0;
        else if (diff < 2) ans = -1;
        else if (diff % 2 ) ans = (diff - 3)/2 + 1;
        else ans = diff/2;

        cout << '#' << i << ' ' << ans << '\n';
    }

    return 0;

}