#include <iostream>
#include <algorithm>
using namespace std;
int n;
pair<int ,int> loc[100000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> loc[i].first >> loc[i].second;
    int x, y;
    sort(loc, loc + n);
    x = loc[n/2].first;
    sort(loc, loc + n, [](const pair<int ,int> &a, const pair<int ,int> &b){
        return a.second < b.second;
    });
    y = loc[n/2].second;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(x - loc[i].first) + abs(y-loc[i].second);
    }
    cout << ans;
    return 0;
}