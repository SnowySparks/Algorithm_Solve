#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef unsigned long long ul;
int n; ul m;
const ul MOD = pow(2, 64);
int a[100000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    ul total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
    sort(a,a+n);
    ul shortage = total - m;
    ul ans = 0;
    for (int i = 0; i < n; ++i) {
        
        ul tmp = min((ul)a[i], (shortage/(n-i)));
        shortage -= tmp;
        ans += tmp*tmp;
        ans %= MOD;
    }
    cout << ans;

    return 0;
}