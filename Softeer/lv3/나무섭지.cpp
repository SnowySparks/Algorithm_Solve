#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int n, m;
pii mv[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int pv[1000][1000];
int gv[1000][1000];
char ch[1000][1001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int sr, sc;
    int er, ec;
    memset(pv, -1, sizeof(pv));
    memset(gv, -1, sizeof(gv));

    queue<pii> pq, gq, cq;

    for (int i = 0; i < n; ++i) {
        cin >> ch[i];
        for (int j = 0; j < m; ++j) {
            if (ch[i][j] == 'G') {
                gv[i][j] = 0;
                gq.push({i,j});
            }
            else if (ch[i][j] == 'N') {
                pv[i][j] = 0;
                pq.push({i, j});
            }
            else if (ch[i][j] == 'D') {
                er = i; ec = j;
                ch[i][j] = '.';
            }
        }
    }
    // 고스트이동
    while (!gq.empty())
    {
        int r= gq.front().first, c = gq.front().second;
        gq.pop();

        for (auto &[dr, dc] : mv) {
            int nr = r + dr, nc=  c + dc;
            if (nr < 0 || nc < 0 || nr >= n || nc >= m || gv[nr][nc]!=-1) continue;
            gv[nr][nc] = gv[r][c] + 1;
            gq.push({nr, nc}); 
        }
    }
    int ans = -1;
    //남우 이동
    while (!pq.empty())
    {
        int r= pq.front().first, c = pq.front().second;
        pq.pop();
        if (r == er && c == ec) {
            ans = pv[r][c];
            break;
        }

        for (auto &[dr, dc] : mv) {
            int nr = r + dr, nc=  c + dc;
            if (nr < 0 || nc < 0 || nr >= n || nc >= m || pv[nr][nc]!=-1) continue;
            if (ch[nr][nc] == '#' || gv[nr][nc] <= pv[r][c]+1) continue;
            pv[nr][nc] = pv[r][c] + 1;
            pq.push({nr, nc}); 
        }
    }

    cout << (ans > 0 ? "Yes" : "No");
    
    return 0;
}

// 원리
// 먼저 고스트들이 각각 다른 위치에 갈 수 있는 최단 시간을 BFS로 구하고
// 남우가 움직일때 해당 위치에 도달할 수 있는 최소 시간이 고스트가 갈 수 있는 시간보다 짧으면 갈 수 있고
// 아니면 못가는거임