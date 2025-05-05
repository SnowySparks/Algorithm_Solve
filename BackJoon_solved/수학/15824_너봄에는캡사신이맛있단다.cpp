#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    ll arr[300005];
    ll pow[300005];
    ll mod = 1e9 + 7;
    ll temp = 1;
    ll p=0, m=0;

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    for (int i=0; i<n; i++) {
        pow[i] = temp-1;
        temp*=2;
        temp%=mod;
    }


    for (int i=0; i<n; i++) {
        p += pow[i] * arr[i];
        m += pow[i] * arr[n-1-i];
        p%=mod;
        m%=mod;
    }
    cout << (p%mod - m%mod + mod) % mod << '\n';
}