#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mn = 1e6+1;
pair<int, int> dt[mn];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> dt[i].second >> dt[i].first;
    }
    sort(dt, dt+n);
    int last = -1;
    int cnt = 0;
    for (auto &[end, start] : dt) {
        if (start >= last) {
            ++cnt;
            last = end;
        }
    } 
    cout << cnt;
    return 0;
}