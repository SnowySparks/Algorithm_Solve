#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> arr;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    arr.resize(n);
    for (int &a : arr) cin >> a;
    int ans = 0;
    int diff = 1000;
    for (int i = n; i >= 2; --i) {
        diff = 1000;
        int loc = find(arr.begin(), arr.end(), i) - arr.begin();
        // cout << loc << '\n';
        if (loc > 0) diff = min(diff, arr[loc] - arr[loc - 1]);
        if (loc + 1 < arr.size()) diff = min(diff, arr[loc] - arr[loc + 1]);
        ans += diff;
        arr.erase(remove(arr.begin(), arr.end(), i), arr.end());
    }
    cout << ans;
    return 0;
}