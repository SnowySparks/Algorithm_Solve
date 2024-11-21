#include <iostream>
using namespace std;
using ll = long long;

int mini_ans[8] = {0,0,1,0,3,2,3,0}; //f(1)

ll max_2n(ll n) {
    ll cnt = 0;
    while (n != 1) {
        n>>=1;
        cnt++;
    }
    return cnt;
} // max 2^n value; ex : 10 --> 3 17 --> 4

ll pow(ll a, ll b) { //fast a^b
    ll res = 1;
    while (b) {
        if (b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

ll func(ll n) {
    if (n < 0) return 0;
    if (n <= 7) return mini_ans[n];
    ll np = max_2n(n);
    ll ne = pow(2,np);
    ll add = (ne - (n - ne + 1));
    return (add > 0 ? add : 0) + 2*func(n - ne);

}

int main(void) {
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1 ; i <= t ; i++) {
        ll n; cin >> n;
        cout << '#' <<i << ' ' << func(n) <<'\n';
    }
    return 0;
}