#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5+1;
vector<pair<int, int> > adj[N];
int n, m;
int st, en;
int p[N];
int v[N];
int fp(int x) {
    if (p[x] == x) return x;
    return p[x] = fp(p[x]);
}
bool unite(int a, int b) {
    a = fp(a);
    b = fp(b);
    if (a == b) return false;
    p[max(a,b)]=min(a,b);
    return true;
}

struct edge {
    int a, b, w;
    bool operator>(const edge &other) const {
        return w > other.w;
    };
    bool operator<(const edge &other) const {
        return w < other.w;
    };
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) p[i] = i;
    cin >> st >> en;
    vector<edge> edges(m);
    for (edge &e :edges) cin >> e.a >> e.b >> e.w;
    sort(edges.begin(), edges.end(), greater<>());
    int cnt = 0;
    for (edge &e :edges) {
        if (cnt == n-1) break;
        if (unite(e.a, e.b)) {
            cnt++;
            adj[e.a].push_back({e.b, e.w});
            adj[e.b].push_back({e.a, e.w});
        }
    }
    v[st] = 1e9;
    queue<int> q; q.push(st);
    while (!q.empty())
    {
        int loc = q.front(); q.pop();
        for (auto [nxt, w] : adj[loc]) {
            if (v[nxt]!=0) continue;
            v[nxt] = min(v[loc], w);
            q.push(nxt);
        }
    }
    cout << v[en];
    return 0;
}