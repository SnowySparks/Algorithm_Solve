#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int n;
ll k;
ll A[30000];
ll B[30000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    sort(A,A+n);
    sort(B,B+n);
    ll ans = 0;
    ll l = 1, r = A[n-1]*B[n-1];

    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += upper_bound(A, A+n, mid/B[i]) - A;
            if (cnt >= k) break;
        }
        if (cnt < k) {
            l = mid + 1;
        }
        else {
            ans = mid;
            r = mid - 1;
        }

    }
    cout << ans;
    return 0;
}