#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
const int max_edge = 5e5+1;
const int max_v = 1e5+1;
struct io {
    int n1, n2;
    long long d;
};

io edge[max_edge];
int p[max_v];

int parent(int x) {
    if (x == p[x]) return x;
    return p[x] = parent(p[x]);
}

bool merge(int a, int b) {
    a = parent(a);
    b = parent(b);
    if (a == b) return false;
    p[max(a, b)] = min(a, b);
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    long long total_dist = 0;
    for (int i = 1; i <= n; ++i) p[i] = i;
    for (int i = 0; i < m; ++i) {
        cin >> edge[i].n1 >> edge[i].n2 >> edge[i].d;
        total_dist += edge[i].d;
    }
    sort(edge, edge + m, [](const io &a, const io &b) {
        return a.d < b.d;
    });

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        if (merge(edge[i].n1, edge[i].n2)) {
            total_dist -= edge[i].d;
            cnt++;

            if (cnt == n-1) break;
        }
    }
    if (cnt == n-1) cout << total_dist;
    else cout << -1;

    return 0;
}