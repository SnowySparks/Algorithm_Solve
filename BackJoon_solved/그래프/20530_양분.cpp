#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define VISITED 1
#define NOT_CYCLED -2
#define CYCLED 2
using namespace std;
const int inf = 1'000'007;
typedef pair<int ,int> pii;
const int N = 200'001;
vector<int> adj[N]; 
int v[N];
int grp[N];
int n, q;

void init() {
    cin >> n >> q;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int dfs(int now, int pre) {
    if (v[now] == VISITED ) return now;
    v[now] = VISITED; 
    for (int e : adj[now]) {
        if (e == pre) continue; 
        int r = dfs(e,now); 
        if (r == NOT_CYCLED) return NOT_CYCLED; 
        if (r >= 1) { 
            v[now] = CYCLED; 
            if (now == r) return NOT_CYCLED;
            else return r;
        }
    }
    return -1;
}

void find_grp() {
    queue<int> q;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i] == CYCLED) {
            grp[i] = ++cnt;
            q.push(i);

            while (!q.empty())
            {
                int loc = q.front();
                q.pop();
                for (int nxt : adj[loc]) {
                    if (v[nxt] == CYCLED) continue;
                    if (grp[nxt]) continue;
                    grp[nxt] = cnt;
                    q.push(nxt);
                }
            }
        }
    }
}

void query() {
    int a, b;
    for (int query = 0; query < q; ++query) {
        cin >> a >> b;
        if (v[a] == CYCLED && v[b] == CYCLED) cout << 2 << '\n';
        else if (grp[a] == grp[b]) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    init();
    dfs(1, -1);
    find_grp();
    query();
    return 0;
}