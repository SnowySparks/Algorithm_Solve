#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 1e5+1;
using pii = pair<int ,int>;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unordered_map<int, int> mp;
    int n, k, tmp; cin >> n >> k;
    vector<pair<int ,int> > v;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        mp[tmp]++;
    }

    for (auto it : mp) {
        v.push_back(it);
    }
    
    sort(v.begin(), v.end(), [](const pii &a, const pii &b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    } );

    for(int i = 0; i < k; ++i) {
        cout << v[i].first <<' ';
    }
    return 0;
}