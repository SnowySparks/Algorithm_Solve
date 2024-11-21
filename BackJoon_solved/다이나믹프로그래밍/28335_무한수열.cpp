#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define f(a,b,c) for(ll a=b;a<=c;a++)
const int inf = 5e5+1;

ll inp[inf];
ll first_sum = 0;
ll n;

ll arrval(ll loc, bool start = false) {
    if (start) loc--;
    return inp[loc % n] - n * (loc / n);
}

ll sigma(ll loc, bool start = false) {
    if (start) loc--;
    ll c = loc / n;
    ll ret = first_sum * c  - (c > 1 ? c*(c-1)/2 : 0) *(n*n);
    for (ll i = c*n; i <= loc; i++) ret += arrval(i);
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    f(i,0,n-1) cin >> inp[i];
    f(i,0,n-1) {
        inp[i] -= (i+1);
        first_sum += inp[i];
    }
    ll p = first_sum / n;
    vector<ll> arr; 
    if (p < 2*n) {
        arr.assign(max(2*n-1, p+n-1)+1,0);
        f(i, 0, arr.size()-1) arr[i]=arrval(i);}
    else {
        arr.assign(3*n+1,0);
        f(i, 0 , 2*n -1 ) arr[i] = arrval(i);
        arr[2*n] = (sigma(p-1) - sigma(2*n-1));
        for (ll i = 2*n + 1 ,t = p; i <= 3*n; i++, t++) arr[i] = arrval(t);
    }
    ll dp_val = arr[0];
    ll ans = max(dp_val, (ll)0);
    f(i, 1, arr.size()-1) {
        dp_val = max(dp_val + arr[i], arr[i]);
        ans = max(ans,dp_val);
    }
    cout << ans;

    return 0;
} 