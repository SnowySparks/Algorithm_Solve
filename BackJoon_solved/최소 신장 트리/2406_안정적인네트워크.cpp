#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)

int n, m;
int p[1001];
struct edge {
    int a, b, w;
};
int findp(int x) {
    if (p[x] == x) return x;
    return p[x] = findp(p[x]);
}
bool unite(int a, int b) {
    a = findp(a);
    b = findp(b);
    if (a == b) return false;
    p[b] = a;
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f(i, 1, n+1) p[i] = i;
    f(i,0,m) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }
    vector<edge> edges;
    f(i, 1, n+1) {
        f(j, 1, n+1) {
            int w; cin >> w;
            if (i == 1 || j == 1) continue;
            if (findp(i) == findp(j)) continue;
            if (i >= j) continue;
            edges.push_back({i, j, w});
        }
    }
    int needCost = 0;
    vector<pair<int ,int> > needEdges;
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b){
        return a.w < b.w;
    });
    for (auto &[a, b, w] : edges) {

        if (unite(a, b)) {
            needEdges.push_back({a, b});
            needCost+= w;
        }
    }
    cout << needCost << ' ' << needEdges.size() << '\n';
    for (auto &[a, b] : needEdges) {
        cout << a << ' ' << b << '\n';
    }
    return 0;
}