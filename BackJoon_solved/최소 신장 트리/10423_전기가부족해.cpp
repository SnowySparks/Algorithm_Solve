#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using piii = pair<int, pair<int, int> >;
const int inf = 1001;
int p[inf];
vector<int> reactor;
int n, m, k;
int parent(int a) {
    if (p[a] == a) return a;
    return p[a] = parent(p[a]);
}

bool un(int a, int b) {
    a = parent(a);
    b = parent(b);
    if (a == b) return false;
    p[max(a,b)] = min(a,b);
    return true;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n ; i++) p[i] = i;
    vector<piii> edges;
    int a, b, c;
    while(k--) {
        cin >> a;
        reactor.push_back(a);
    }
    if (reactor.size() > 1) {
        for (int i = 1 ; i < (int)reactor.size() ; i++) {
            un(reactor[i-1],reactor[i]);
        }
    }
    while(m--) {
        cin >> a >> b >> c;
        edges.push_back({c,{a,b}});
    }
    sort(edges.begin(),edges.end());
    long long ans = 0;
    for (piii e : edges) {
        a = e.second.first;
        b = e.second.second;
        if (un(a,b)) {
            ans += e.first;
        }
    }
    cout << ans;
    return 0;
}