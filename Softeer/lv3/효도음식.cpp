#include <iostream>
#include <algorithm>
#include <cstring>
#define f(a, b, c) for (int a =b; a < c; ++a)
using namespace std;
const int inf = 1e5+3;
int arr[inf];
int dp_left[inf];
int dp_right[inf];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    f(i, 1, n+1) cin >> arr[i];
    arr[0] = arr[n+1] = dp_left[0] = dp_right[n+1] = -1e9;

    f(i, 1, n+1) {
        dp_left[i] = max(dp_left[i-1] + arr[i], arr[i]);
    }
    for (int i = n; i >= 1; --i) {
        dp_right[i] = max(dp_right[i+1] + arr[i], arr[i]);
    }

    f(i, 1, n+1) {
        dp_left[i] = max(dp_left[i-1], dp_left[i]);
    }
    for (int i = n; i >= 1; --i) {
        dp_right[i] = max(dp_right[i], dp_right[i+1]);
    }

    // f(i, 1, n+1) {
    //     cout << dp_left[i] <<'\t';
    // }
    // cout << '\n';
    // f(i, 1, n+1) {
    //     cout << dp_right[i] <<'\t';
    // }
    // cout <<'\n';

    int ans = -1e9;

    f(i, 1, n-1) {
        ans = max(ans, dp_left[i] + dp_right[i+2]);
    }
    for (int i = n; i >= 3; --i) {
        ans = max(ans, dp_right[i] + dp_left[i-2]);
    }
    cout << ans;
    return 0;
}