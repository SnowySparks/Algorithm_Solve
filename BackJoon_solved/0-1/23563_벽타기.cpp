#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
using pii = pair<int, int>;
const int mv[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int H, W;
char m[500][502];
bool nearWall[500][500];
int dist[500][500];
struct info {
    int r, c, t;
};

bool isIn(int r, int c) {
    if (r < 0 || r >= H || c < 0 || c >= W) return false;
    return true;
}

bool isNearWall(int r, int c) {
    for (auto [dr, dc] : mv) {
        int nr = r + dr, nc = c + dc;
        if (isIn(nr,nc) && m[nr][nc] == '#') return true;
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dist, -1, sizeof(dist));
    deque<info> dq;
    int ans = 1000000;
    cin >> H >> W;
    for (int r = 0; r < H; ++r) {
        cin >> m[r];
        for (int c = 0; c < W; ++c) {
            if (m[r][c] == 'S') {
                dist[r][c] = 0;
                dq.push_back({r, c, 0});
            }
            else {
                dist[r][c] = 1000000;
            }
        }
    }

    while (!dq.empty())
    {
        auto [r, c, t] = dq.front(); dq.pop_front();
        if (m[r][c] == 'E') {
            ans = min(ans, t);
        }
        bool nowNearWall = isNearWall(r, c);
        for (auto [dr, dc] : mv) {
            int nr = r + dr, nc = c + dc;
            if (!isIn(nr, nc)) continue;
            if (m[nr][nc] == '#') continue;
            if (nowNearWall && isNearWall(nr, nc)) {
                if (dist[nr][nc] <= t) continue;
                dist[nr][nc] = t;
                dq.push_front({nr, nc, t});
            }
            else {
                if (dist[nr][nc] <= t+1) continue;
                dist[nr][nc] = t+1;
                dq.push_back({nr, nc, t+1});
            }
        }
    }

    cout << ans;
    return 0;
}