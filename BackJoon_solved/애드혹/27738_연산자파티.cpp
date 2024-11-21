#include <iostream>
using namespace std;
using ll = long long;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N; cin >> N;
    ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    ll x = 0;
    for (ll i = N/f*f+1 ; i<=N;i++) {
        if (i%a==0) x+=i;
        if (i%b==0) x%=i;
        if (i%c==0) x&=i;
        if (i%d==0) x^=i;
        if (i%e==0) x|=i;
        if (i%f==0) x=x>>i;
    }
    cout << x;
}