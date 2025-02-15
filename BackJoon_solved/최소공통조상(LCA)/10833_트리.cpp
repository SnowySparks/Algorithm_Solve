#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n;
int parent[N];
int color[N];
int check[N]; // Lca 탐색 시 지나간 자리

int find_lca(int a, int b, int k) {
    if (a == 0 || b == 0) return 0;
    if (a == b) return a;
    for (int i = 0; i < 1000; ++i) {
        check[a] = k;
        a = parent[a];
        if (a == -1) break;
    }
    for (int i = 0; i < 1000; ++i) {
        if (check[b] == k) return b;
        check[b] = k;
        b = parent[b];
        if (b == -1) break;
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt","r",stdin);
    int q;
    parent[0] = -1;
    color[0] = -1;
    set<int> s;
    cin >> n >> q;
    int a, b, r, c;
    int lca;
    for (int query = 1; query <= q; ++query) {
        cin >> r;
        switch (r)
        {
        case 1:
            cin >> a >> b >> c;
            if (a == b) continue;
            lca = find_lca(a, b, query);
            for (int i = a; i != lca; i=parent[i]) color[i]=c;
            for (int i = b; i != lca; i=parent[i]) color[i]=c;
            break;
        case 2:
            cin >> a >> b;
            parent[a]=b;
            break;
        case 3:
            cin >> a >> b;
            lca = find_lca(a, b, query);
            s.clear();
            for (int i = a; i != lca; i=parent[i]) s.insert(color[i]);
            for (int i = b; i != lca; i=parent[i]) s.insert(color[i]);
            cout << s.size() <<'\n';
            break;
        }
    }
    return 0;
}