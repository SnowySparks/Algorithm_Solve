#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[200000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    int ans = 1;
    vector<int> r; 
    for (int i = 0 ; i < n ; i++) {
        if (r.empty() || r.back() < arr[i]) {
            r.push_back(arr[i]);
            ans = max(ans, (int)r.size());
        }
        else {
            auto it = lower_bound(r.begin(), r.end(),arr[i]);
            *it = arr[i];
            ans = max(ans, (int) (it - r.begin())+1);
        }
    }
    cout << n - ans;
    return 0;
}