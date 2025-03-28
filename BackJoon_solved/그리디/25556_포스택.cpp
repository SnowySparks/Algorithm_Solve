#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int arr[100000], n;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vector<int> v;
    for (int i = n-1; i >= 0; --i) {
        if (v.empty() || v.back() < arr[i]) v.push_back(arr[i]);
        else {
            auto loc = lower_bound(v.begin(), v.end(), arr[i]);
            *loc = arr[i];
        }
    }

    cout << (v.size() <= 4 ? "YES" : "NO");

    return 0;
}