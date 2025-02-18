#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
const int inf =1e9 + 7;
int maxFlow[1001][1001];
int n, m, k;
struct edge {
    int n1, n2, w;
    bool operator<(const edge &other) const {
        return w < other.w;
    }
    bool operator>(const edge &other) const {
        return w > other.w;
    }
};
vector<pair<int, int> > adj[1001]; //MST Tree
bool v[1001];

void dfs(int start, int loc, int maxW) {
    for (auto [nxtChild, flow] : adj[loc]) {
        if (v[nxtChild]) continue;
        v[nxtChild] = true;
        int minW = min(maxW, flow);
        maxFlow[start][nxtChild] = minW;
        maxFlow[nxtChild][start] = minW;
        dfs(start, nxtChild, minW);
    }
}

int p[1001];
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

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> m >> k;
    f(i, 1, n+1) p[i] = i; // uf 부모

    vector<edge> edges(m);
    for (edge &e : edges) {
        cin >> e.n1 >> e.n2 >> e.w;
    };
    sort(edges.begin(), edges.end(), greater<>());
    int cnt = 0;
    for (auto [n1, n2, w] : edges) {
        if (cnt == n-1) break; //트리 간선 개수 : n-1
        if (unite(n1, n2)) {
            ++cnt;
            adj[n1].push_back({n2, w});
            adj[n2].push_back({n1, w});
        }
    }
    f(i, 1, n+1) {
        memset(v, 0, sizeof(v));
        v[i] = true;
        dfs(i, i, inf);
    }

    f(i, 0, k) {
        int a, b;
        cin >> a >> b;
        cout << maxFlow[a][b] << '\n';
    }

    return 0;
}