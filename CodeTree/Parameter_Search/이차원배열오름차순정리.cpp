#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k; cin >> n >> k;

    int ans = 0;
    int l = 1, r = k; 
    while(l <= r) {
        int mid = (l + r) >> 1;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            cnt += min(n, mid/i);
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