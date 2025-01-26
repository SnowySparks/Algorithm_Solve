#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 1;
int n, m, q;
int p[MAXN];
int cnt[MAXN];
vector<pair<int ,int> > edges;
bool isCut[MAXN];

void init() {
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        cnt[i] = 1;
    }
}

int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    cnt[min(a, b)] += cnt[max(a, b)];
    p[max(a, b)] = min(a, b);
    return true;
}



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> m >> q;
    init();
    edges.resize(m);
    for (pair<int, int> &edge : edges) {
        cin >> edge.first >> edge.second;
    }
    vector<int> query(q);
    for (int &val : query) {
        cin >> val;
        val--;
        isCut[val] = true;
    }

    for (int i = 0; i < m; ++i) {
        if (!isCut[i]) {
            auto [a, b] = edges[i];
            unite(a, b);
        }
    }
    long long ans = 0;
    for (int i = q-1; i >= 0; --i) {
        int a = edges[query[i]].first, b = edges[query[i]].second;
        a = find(a); b = find(b);
        if (a != b) {
            ans += (1LL*cnt[a])*(1LL*cnt[b]);
            unite(a, b);
        }
    }
    cout << ans;
    return 0;
}