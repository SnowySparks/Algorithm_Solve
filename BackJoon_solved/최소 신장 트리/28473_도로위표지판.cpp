#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 2e5+1;
int n, m;
int parent[MAXN];

struct Edge {
    int x, y, z, w; 
};

int findp(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findp(parent[x]);
}

bool unite(int a, int b) {
    a = findp(a); b = findp(b);
    if (a == b) return false;
    parent[max(a, b)] = min(a, b);
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 1; i <= n; ++i) parent[i] = i;
    for (Edge &e : edges) {
        cin >> e.x >> e.y >> e.z >> e.w;
    }
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){
        if (a.z == b.z) {
            return a.w < b.w;
        }
        return a.z < b.z;
    });
    long long ansCost = 0;
    int connectedEdgeCnt = 0;
    string nums = "";

    for (Edge &e : edges) {
        if (connectedEdgeCnt == n-1) break;
        if (unite(e.x, e.y)) {
            connectedEdgeCnt++;
            nums.push_back('0' + e.z);
            ansCost += e.w;
        }
    }
    if (connectedEdgeCnt != n-1) cout << -1;
    else {
        cout << nums << ' ' << ansCost;
    }

    return 0;
}