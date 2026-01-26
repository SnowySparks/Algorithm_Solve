#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 250'001;
int n;
vector<int> adj[N];
int dfs_parent_node[N];
int parent[N];
int grp_cnt[N];
int inp[N];
bool isS[N];
bool isUsed[N];

int findp(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findp(parent[x]);
}

bool isSameParent(int a, int b) {
    return findp(a) == findp(b);
}

void unite(int a, int b) {
    a = findp(a);
    b = findp(b);

    if (!isSameParent(a, b)) {
        grp_cnt[min(a, b)] += grp_cnt[max(a, b)];
        parent[max(a, b)] = min(a, b);
    }
}

void input() {
    cin >> n;
    int a, b;
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        grp_cnt[i] = 1;
    }
}


void dfs(int node, int pnode) {
    for (int nxt : adj[node]) {
        if (nxt == pnode) continue;
        dfs_parent_node[nxt] = node;
        dfs(nxt, node);
    }
}

void query() {
    int q; cin >> q;
    int cnt;
    
    long long ans = 0;

    while (q--)
    {
        ans = 0;

        // input
        cin >> cnt;
        for (int i = 0; i < cnt; ++i) {
            cin >> inp[i];
            isS[inp[i]] = true;
        }

        // merge
        for (int i = 0; i < cnt; ++i) {
            int node = inp[i];
            int pnode = dfs_parent_node[node];
            if (isS[ pnode ]) {
                // cout << node << ' ' << pnode << '\n';
                unite(node, pnode);
            }
        }
        
        //cal
        for (int i = 0; i < cnt; ++i) {
            int ancestor = findp(inp[i]);
            if (!isUsed[ancestor]) {
                isUsed[ancestor] = true;
                long long tmp = grp_cnt[ancestor];
                ans += ( ( tmp * (tmp - 1) ) / 2 );
            }
        }

        cout << ans << '\n';

        //rollback
        for (int i = 0; i < cnt; ++i) {
            int node = inp[i];
            grp_cnt[node] = 1;
            parent[node] = node;
            isUsed[node] = false;
            isS[node] = false;
            inp[i] = 0;
        }
    }
    

}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    input();
    dfs(1, 0);
    query();
    return 0;
}