#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
const int mv[4][2] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
};
int n, m, C, sr, sc;
int dist[1000][1000];
int gh[1000][1000];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> C;
    cin >> sr >> sc; sr--; sc--;
    f(i, 0, n) f(j, 0, m) cin >> gh[i][j];
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int> > q; q.push({sr, sc}); dist[sr][sc] = 0;
    int maxL = 0;
    while (!q.empty())
    {
        auto [r, c] = q.front(); q.pop();
        for (auto [dr, dc] : mv) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (gh[nr][nc] == -1 || dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c]+1;
            maxL = max(maxL, dist[nr][nc]);
            q.push({nr, nc});
        }
    }
    vector<int> revenueByL(maxL+1);
    f(i, 0, n) f(j, 0, m) {
        if (gh[i][j] > 0 && dist[i][j] >= 0) revenueByL[dist[i][j]] += gh[i][j];
    }
    int ans = 0;
    f(i, 0, maxL+1) {
        if (i > 0) revenueByL[i] += revenueByL[i-1];
        ans = max(ans, revenueByL[i] - C*i);
    }
    cout << ans;
    return 0;
}