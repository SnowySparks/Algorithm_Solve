#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
using pii = pair<int, int>;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pii> pts(2*n);
    f(i, 0, n) {
        int fr, to; cin >> fr >> to;
        pts[2*i] = {fr, 1};
        pts[2*i+1] = {to, -1};
    }

    sort(pts.begin(), pts.end());

    int ans = 0;
    int cnt = 0;
    for (auto &[pts, state] : pts) {
        cnt += state;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}