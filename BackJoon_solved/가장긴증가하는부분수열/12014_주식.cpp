#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
int arr[10000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int T; cin >> T;
    vector<int> lst;
    for (int test = 1; test <= T; ++test) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> arr[i];
        lst.clear();
        for (int i = 0; i < n; ++i) {
            if (lst.empty() || lst.back() < arr[i]) {
                lst.push_back(arr[i]);
            }
            else {
                auto loc = lower_bound(lst.begin(), lst.end(), arr[i]);
                *loc = arr[i];
            }
        }
        cout << "Case #" << test <<'\n';
        cout << (k <= lst.size() ? 1 : 0) << '\n';
    }

    return 0;
}