#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll defaultHeight = 0, ans = 0, h = 0;
    int n; cin >> n;
    vector<pii> arr(n);
    for (pii &a : arr) cin >> a.first >> a.second;

    sort(arr.begin(), arr.end(), [](const pii &a, const pii &b) {
        int aDiff = a.first - a.second;
        int bDiff = b.first - b.second;

        return aDiff > bDiff;
    });

    for (pii &a : arr) {
        ans += a.first + h;
        h += a.first - a.second;
        defaultHeight = min(defaultHeight, h);
    }

    ans -= defaultHeight * n;
    cout << ans;
    
}