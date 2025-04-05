#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1e9;
int n;
struct Route {
    int s, e, c;
};

Route routes[200000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> routes[i].s >> routes[i].e >> routes[i].c;
    }
    sort(routes, routes+n, [](Route &a, Route &b){
        return a.s < b.s;
    });

    int s = -1, e = -1, c = inf;
    vector<Route> ans;
    for (int i = 0; i < n; ++i) {
        if (e < routes[i].s) {
            if (e >= 0) ans.push_back({s, e, c});
            s = routes[i].s;
            e = routes[i].e;
            c = routes[i].c;
        }
        else {
            e = max(e, routes[i].e);
            c = min(c, routes[i].c);
        }
    }
    ans.push_back({s, e, c});
    cout << ans.size() <<'\n';
    for (auto [s, e, c] : ans) {
        cout << s << ' ' << e <<' ' << c << '\n';
    }
    return 0;
}