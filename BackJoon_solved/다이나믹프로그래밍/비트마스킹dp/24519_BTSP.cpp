#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define NOT_VISITED -1
int n, m;
const int INF = 1e9 + 7;
int dist[18][18];
int dp[18][1<<18];
vector<int> path;
int dfs(int cur, int state) {
    //현재 방문 도시, 현재 방문 상태
    if (state == (1<<n)-1) {
        return dist[cur][0];
    }
    int &ret = dp[cur][state];
    if (ret != -1) return ret;
    ret = INF;
    int next_node = 0;
    for (int i = 0; i < n; ++i) {//다음 도시 방문
        if (state & (1 << i) ) continue; //이미 찍먹상태
        if ( dist[cur][i] == INF) continue; //방문불가
        ret = min(ret, max(dfs(i, state | (1 << i)), dist[cur][i]));
    }
    return ret;
}

void find_path(int cur, int state) {
    if (state == (1<<n)-1) {
        return;
    }
    int ret = INF;
    int next_node = 0;
    for (int i = 0; i < n; ++i) {
        if (state & (1 << i) ) continue; //이미 찍먹상태
        if ( dist[cur][i] == INF) continue; //방문불가
        if (ret > max(dp[i][state | (1 << i)], dist[cur][i])) {
            next_node = i;
            ret = max(dp[i][state | (1 << i)], dist[cur][i]);
        }
    }
    path.push_back(next_node);
    find_path(next_node, state | (1 << next_node));
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = INF;
        }
    }
    int u, v, c;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        dist[u-1][v-1] = c;
    }
    int res = dfs(0, 1);

    if (res == INF) {
        cout << -1;
        return 0;
    }

    path.push_back(0);
    cout << res << '\n';
    find_path(0, 1);
    for (int node : path) {
        cout << node + 1 <<' ';
    }

    return 0;
}