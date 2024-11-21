#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int inf = 1e5+1;
string inp[inf];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int inf = 1e5+1;
    unordered_map<int, int> mp;
    int n, k, tmp; cin >> n >> k;
    
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        mp[tmp]++;
    }

    int ans = 0;
    unordered_map<int, bool> use;
    for (pair<int, int> res : mp) {
        if (mp.find(k-res.first) == mp.end()) continue;
        if (use[res.first]) continue;
        if (use[k-res.first]) continue;

        use[res.first] = true;
        use[k-res.first] = true;

        // 두 수가 동일한 경우 고려
        if (k == 2*res.first) {
            ans += mp[res.first] * (mp[k-res.first] -1 )/2;
        }
        else {
            ans += mp[res.first] * mp[k-res.first] ; }

    }
    cout << ans;
    
    return 0;
}