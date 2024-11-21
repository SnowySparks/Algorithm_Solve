#include <iostream>
using namespace std;
using ll = long long;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n ; cin >> n;
    ll ans = 6;
    for (int i = 11 ; i <= n ; i ++) ans*=i;
    cout << ans;
    return 0;
}