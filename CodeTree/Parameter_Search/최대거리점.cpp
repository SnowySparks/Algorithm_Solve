// https://www.codetree.ai/missions/8/problems/maximum-distance-point/description
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int max_n = 2e5;
int n, m, arr[max_n];

int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);

    int l = 0, r = arr[n-1]; // 

    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1; //최소 이정도 거리가 있어야 함
        int cnt = 1, pts = arr[0];

        for (int i = 1; i < n; ++i) {
            if (arr[i] - pts > mid) {
                ++cnt;
                pts = arr[i];
            }
        }

        if (cnt >= m) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans+1;

    return 0;
}