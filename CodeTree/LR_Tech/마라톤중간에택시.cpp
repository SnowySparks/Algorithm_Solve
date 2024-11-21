#include <iostream>
#include <cstring>
#include <queue>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
using pii = pair<int, int>;
const int inf = 1e9+10;
const int MAX_N = 1000;
int dist(const pii &a, const pii &b) {
    return abs(a.first -b.first) + abs(a.second - b.second);
}

pii pts[MAX_N + 1];
int ldp[MAX_N+1];
int rdp[MAX_N+1];
int n;
int ans = inf;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);  
    cin >> n;

    f(i, 1, n+1) cin >> pts[i].first >> pts[i].second;
    f(i, 2, n+1) ldp[i] = ldp[i-1] + dist(pts[i-1], pts[i]);
    for (int i = n-1; i >= 1; --i) rdp[i] = rdp[i+1] + dist(pts[i], pts[i+1]);

    for (int i = 2; i <= n-1; ++i) {
        ans = min(ans, ldp[i-1] + rdp[i+1] + dist(pts[i-1], pts[i+1]));
    }
    cout << ans;
    return 0;
}

