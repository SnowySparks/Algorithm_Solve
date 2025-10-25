#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;
const int inf = 1e9 + 7;
int n, p, q, r;
ll s;
int arr[N];

void init() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cin >> p >> q >> r >> s;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();

    int ans = -1;
    int minVal = 1, maxVal = 2e5;

    while (minVal <= maxVal) {
        int mid = (minVal + maxVal) >> 1;

        ll cal = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > (mid + r)) {
                cal += arr[i] - p;
            }
            else if (arr[i] < mid) {
                cal += arr[i] + q;
            }
            else {
                cal += arr[i];
            }
        }

        if (cal >= s) {
            ans = mid;
            maxVal = mid - 1;
        }
        else {
            minVal = mid + 1;
        }
    }
    cout << ans;
    return 0;
}