#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1'000'000'000
#define N 251
#define f(a, b, c) for(int a=b; a<c; ++a)
int n, m;
int d[N][N];

void init() {
    cin >> n >> m;
    f(i, 1, n+1) {
        f(j, 1, n+1) {
            d[i][j] = MAX;
        }
        d[i][i] = 0;
    }

    int u, v, b;
    f(q, 0, m) {
        cin >> u >> v >> b;
        d[u][v] = 0;
        d[v][u] = 1-b;
    }
}

void simulation() {
    f(mid, 1, n+1) {
        f(s, 1, n+1) {
            f(e, 1, n+1) {
                d[s][e] = min(d[s][e], d[s][mid] + d[mid][e]);
            }
        }
    }
}

void query(int q) {
    int a, b;
    f(query, 1, q+1) {
        cin >> a >> b;
        cout << d[a][b] << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    init();
    simulation();
    int q; cin >> q;
    query(q);
    return 0;
}