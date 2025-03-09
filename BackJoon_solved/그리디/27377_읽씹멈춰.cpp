#include <iostream>
using namespace std;
typedef unsigned long long ll;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    ll n, s, t;
    while (T--)
    {
        cin >> n >> s >> t;
        ll ans = 0;
        while (n > 0)
        {
            if (n % 2 == 1) {
                ans += s;
                n--;
            }
            else {
                n/=2;
                ans += min(n*s, t);
            }
        }
        cout << ans << '\n';
    }    
    return 0;
}