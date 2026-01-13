#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 2'222 + 1;
const int H = 13;
int n, q;
int level[N] = {0, };
int p_node[N][H];
int dfs_reverse_to_node[N];
int prefix[N];
bool v[N];
vector<int> adj[N];
queue<int> que;

void init() {
    cin >> n >> q;
    int a, b;
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void set_tree(int node, int pnode) {
    level[node] = level[pnode] + 1;
    p_node[node][0] = pnode;
    for (int lv = 1; lv < H; ++lv) {
        p_node[node][lv] = p_node[ p_node[node][lv-1] ][lv - 1];
    }
    for (int nxt : adj[node]) {
        if (nxt == pnode) continue;
        set_tree(nxt, node);
    }
}

void dfs(int node, int pnode) {
    int cnt = 0;
    for (int nxt : adj[node]) {
        if (nxt == pnode) continue;
        dfs_reverse_to_node[nxt] = node;
        cnt++;
        dfs(nxt, node);
    }
}

int lca(int a, int b) {
    if (a == 1 || b == 1) return 1;
    if (level[a] < level[b]) swap(a, b);
    int lv_diff = level[a] - level[b];

    for (int i = 0;lv_diff; ++i) {
        if (lv_diff & 1) a = p_node[a][i];
        lv_diff >>= 1;
    }
    if (a == b) return a;

    for (int i = H-1; i >= 0; --i) {
        if (p_node[a][i] != p_node[b][i]) {
            a = p_node[a][i];
            b = p_node[b][i];
        }
    }
    return p_node[a][0];
}

void query() {
    int a, b;
    while(q--) {
        cin >> a >> b;
        if (level[a] < level[b]) swap(a, b);
        int c = lca(a, b);

        if (c == b) {
            prefix[a]++;
            prefix[b]--;
        }
        else {
            prefix[c] -= 2;
            prefix[a]++;
            prefix[b]++;
        }

    }
}

void post(int node, int pnode) {
    for (int nxt : adj[node]) {
        if (nxt == pnode) continue;
        post(nxt, node);
        prefix[node] += prefix[nxt];
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    init();
    set_tree(1, 0);
    dfs(1, 0);
    query();
    post(1, 0);

    int a = N + 1, b = N + 1, c = -1;

    for (int i = 2; i <= n; ++i) {
        if (prefix[i] > c) {
            a = i;
            b = p_node[i][0];
            c = prefix[i];
        }
        else if (prefix[i] == c) {
            int j = p_node[i][0];
            if (i < a || j < a) {
                a = i;
                b = j;
            }
        }
        else continue;
        if (a > b) swap(a, b);
    }

    cout << a << ' ' << b << ' ' << c;

    return 0;
}