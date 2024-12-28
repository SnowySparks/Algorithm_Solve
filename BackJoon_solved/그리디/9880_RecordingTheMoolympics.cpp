#include <iostream>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
pii arr[200];
int n;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr+n, [](pii &a, pii &b) {
        return a.second < b.second;
    });
    multiset<int> room;
    room.insert(0);
    room.insert(0);
    int from, to;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        tie(from, to) = arr[i];
        multiset<int>::iterator it = room.upper_bound(from);
        if (it == room.begin()) continue;
        it--;
        int val = *it;
        ++ans;
        room.erase(it);
        val = to;
        room.insert(val);
    }
    cout << ans;
    return 0;
}