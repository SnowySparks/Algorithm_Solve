#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
const int source = 1;
const int sink = 2;
const int inf = 1e9;
int n, m, k;
int flow[501][501];
int capacity[501][501];
int lv[501];
int work[501];
vector<int> adj[501];

bool bfs() {
    memset(lv, 0, sizeof(lv));
    lv[source] = 1;
    queue<int> q; q.push(source);
    while (!q.empty())
    {   
        int node = q.front();
        q.pop();
        for (int nxt : adj[node]) {
            if (!lv[nxt] && capacity[node][nxt] > flow[node][nxt]) {
                lv[nxt] = lv[node] + 1;
                q.push(nxt);
            }
        }
    }
    return lv[sink] > 0;
}

int dfs(int cur, int minFlow) {
    if (cur == sink) return minFlow;
    for (int &i = work[cur]; i < adj[cur].size(); ++i) {
        int nxt = adj[cur][i];
        if (lv[nxt] == lv[cur] + 1 && capacity[cur][nxt] - flow[cur][nxt] > 0) {
            int df = dfs(nxt, min(minFlow,capacity[cur][nxt] - flow[cur][nxt]));
            if (df > 0) {
                flow[cur][nxt]+=df;
                flow[nxt][cur]-=df;
                return df;
            }
        }
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int T; cin >> T;
    f(test, 1, T+1) {
        memset(flow, 0, sizeof(flow));
        memset(capacity, 0, sizeof(capacity));
        memset(lv,-1,sizeof(lv));
        cin >> k >> n >> m;
        f(i, 0, n+1) adj[i].clear();
        f(i, 0, m) {
            int a, b; cin >> a >> b;
            if (a == 1 && b == 2) {
                capacity[a][b]++;
            }
            else {
                capacity[a][b] = 1;
            }
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int reach = 0;
        while (bfs()) {
            memset(work, 0, sizeof(work));
            while(1) {
                int f = dfs(source, inf);
                if (f == 0) break;
                reach += f;
            }
        }
        cout << '#' << test << ' ' << (reach >= k ? "YES" : "NO") << '\n';
    }
    return 0;
}