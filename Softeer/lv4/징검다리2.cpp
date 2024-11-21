#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define MAXN 300000
int l[MAXN], r[MAXN], arr[MAXN];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> lst;
    for (int i = 0; i < n ; ++i) cin >> arr[i];

    for (int i = 0 ; i < n; ++i) {
        if (lst.empty() || lst.back() < arr[i]) {
            lst.push_back(arr[i]);
            l[i] = (int) lst.size();
        }
        else {
            vector<int>::iterator it = lower_bound(lst.begin(), lst.end(), arr[i]);
            *it = arr[i];
            l[i] = it - lst.begin() + 1;
        }
    }

    lst.clear();
    for (int i = n-1 ; i >= 0; --i) {
        if (lst.empty() || lst.back() < arr[i]) {
            lst.push_back(arr[i]);
            r[i] = (int) lst.size();
        }
        else {
            vector<int>::iterator it = lower_bound(lst.begin(), lst.end(), arr[i]);
            *it = arr[i];
            r[i] = it - lst.begin() + 1;
        }
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) ans = max(ans, l[i] + r[i] - 1);
    cout << ans;

    return 0;
}