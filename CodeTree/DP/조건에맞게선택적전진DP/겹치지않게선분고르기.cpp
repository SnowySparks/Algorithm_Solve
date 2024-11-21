#include <iostream>
#include <algorithm>
#include <cstring>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
using pii = pair<int ,int>;
int n;
pair<int ,int> arr[1000];
int dp[1000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+n, [](const pii &a, const pii &b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    });

    int t = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if ( t < arr[i].first) {
            ans++;
            t = arr[i].second;
        }
    }
    cout << ans;
    return 0;
}