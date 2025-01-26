#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n;
int source = 0, sink;
vector<int> adj[110];

int rowSum[51]; // from 1 to n
int colSum[51]; // from n+1 to 2*n
int total = 0;
int c[110][110];
int f[110][110];

int level[110];
int work[110];
int ansTable[55][55];


bool dinic_bfs() {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(0);
    level[0] = 0;

    while (!q.empty())
    {
        int node = q.front(); q.pop();
        for (int nextNode : adj[node]) {
            if (level[nextNode] == -1 && c[node][nextNode] - f[node][nextNode] > 0) {
                level[nextNode] = level[node] + 1;
                q.push(nextNode);
            }
        }
    }
    return level[sink] != -1;
}

int dinic_dfs(int cur, int flow) {
    if (cur == sink) return flow;
    for (int &i = work[cur]; i < adj[cur].size(); ++i) {
        int nxt = adj[cur][i];
        if ( level[nxt] == level[cur] + 1 && (c[cur][nxt] - f[cur][nxt] > 0)) {
            int res = dinic_dfs(nxt, min(flow,c[cur][nxt] - f[cur][nxt] ));
            if (res > 0) {
                f[cur][nxt] += res;
                f[nxt][cur] -= res;
                return res;
            }
        }
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    sink = 2*n + 1;
    for (int i = 1; i <= n; ++i) cin >> *(rowSum + i);
    for (int i = 1; i <= n; ++i) cin >> *(colSum + i);
    for (int i = 1; i <= n; ++i) total += *(rowSum + i);

    // source -> rowSum
    for (int i = 1; i <= n; ++i) {
        adj[0].push_back(i);
        adj[i].push_back(0);
        c[0][i] = rowSum[i];
    }

    // row -> col;
    for (int row = 1; row <= n; ++row) {
        for (int col = n+1; col <= 2*n; ++col) {
            adj[row].push_back(col);
            adj[col].push_back(row);
        }
    }
    // col -> sink
    for (int col = n+1; col <= 2*n; ++col) {
        adj[sink].push_back(col);
        adj[col].push_back(sink);
        c[col][sink] = colSum[col-n];
    }

    int ans = -1;
    int low = 0, high = max(*max_element(rowSum, rowSum+n+1), *max_element(colSum, colSum+n+1));

    while (low <= high) {
        int mid = (low +high)  >> 1;
        for (int row = 1; row <= n; ++row) {
            for (int col = n+1; col <= 2*n; ++col) {
                c[row][col] = mid;
            }
        }
        memset(f, 0, sizeof(f));
        int cal = 0;
        while (dinic_bfs())
        {
            memset(work, 0, sizeof(work));
            int res = dinic_dfs(0, 100000000);
            if (res == 0) break;
            cal += res;
        }

        if (cal == total) {
            ans = mid;
            for (int row = 1; row <= n; ++row) {
                for (int col = n+1; col <= 2*n; ++col) {
                    ansTable[row][col-n] = f[row][col];
                }
            }
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << ans << '\n';
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= n; ++col) {
            cout << ansTable[row][col] <<' ';
        }
        cout << '\n';
    }
}