#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_n = 100000;
int arr[max_n+1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    int ans = -10001;
    for (int i = 1; i <= n; ++i) {
        arr[i] = max(arr[i-1] +arr[i], arr[i]);
        ans = max(ans, arr[i]);
    }
    cout << ans;
    return 0;
}