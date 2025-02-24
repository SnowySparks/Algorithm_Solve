#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int arr[100000], n, x;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int l = 1, r = n;

    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        priority_queue<int, vector<int>, greater<> > pq;

        int endTime = 0;
        for (int i = 0; i < min(mid,n); ++i) {
            pq.push(arr[i]);
            endTime = max(endTime, arr[i]);
        }
        for (int i = min(mid,n); i < n; ++i) {
            int t = pq.top() + arr[i];
            pq.pop();
            endTime = max(endTime, t);
            if (endTime > x) break;
            pq.push(t);
        }
        if (endTime > x) {
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