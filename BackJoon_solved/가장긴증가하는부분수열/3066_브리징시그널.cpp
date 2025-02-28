#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[40001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int T; cin >> T;
    vector<int> lis;
    while (T--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> arr[i];
        for (int i = 0; i < n; ++i) {
            if (lis.empty() || lis.back() < arr[i]) lis.push_back(arr[i]);
            else {
                auto loc = lower_bound(lis.begin(), lis.end(), arr[i]);
                *loc = arr[i];
            }
        }
        cout << lis.size() << '\n';
        lis.clear();
    }
    

    return 0;
}