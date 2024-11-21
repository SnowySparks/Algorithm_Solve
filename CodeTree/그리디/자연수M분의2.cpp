// https://www.codetree.ai/missions/8/problems/m2-pairs-of-natural-numbers/description
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;
using pii = pair<int ,int>;
#define f(a, b, c) for (int a = b; a < c; ++a)

using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m = 0;

    vector<pii> v(n); // 수, 개수
    f(i, 0, n) {
        cin >> v[i].second >> v[i].first;
        m+= v[i].second;
    }
    sort(v.begin(), v.end());
    int l = 0, r = n-1, ans = -1;

    while (l < r)
    {
        int min_cnt = min(v[l].second, v[r].second);
        ans = max(ans, v[l].first + v[r].first);
        v[l].second-=min_cnt;
        v[r].second-=min_cnt;

        if (!v[l].second) l++;
        if (!v[r].second) r--;
    }
    
    if (v[l].second) ans=max(ans, 2*v[l].first);
    if (v[r].second) ans=max(ans, 2*v[r].first);
    cout << ans;
    return 0;
}