#include <iostream>
#include <cstring>
#include <algorithm>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
using pii = pair<int ,int>;
const int max_cord = 1e5;
int n;
pii cord[max_cord];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) cin >> cord[i].first >> cord[i].second;
    sort(cord, cord+n); 

    int ans = 1, end_pts = cord[0].second;

    f(i, 1, n) {
        auto [st, en] = cord[i];
        if (end_pts >= st) {
            end_pts = max(end_pts, en);
        }
        else {
            end_pts = cord[i].second;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}