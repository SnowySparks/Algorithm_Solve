#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1e9 + 7;
const int MAX_SIZE = 50;
const int mv[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int N, M;
bool vis[MAX_SIZE][MAX_SIZE][4][4]; // r, c, 방문한 곳 status, 어느 방향에서 왔는가
char ch[MAX_SIZE][MAX_SIZE]; //맵

int dummyCCnt = 0;

struct info {
    int r, c, status, dir, cnt;
    // r, c, 방문상태, 방향, 이동횟수
};

bool isIn(int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= M) return false;
    return true;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int sr = 0, sc = 0; // 시작점

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> ch[i][j];
            if (ch[i][j] == 'S') {
                sr = i; sc = j;
                ch[i][j] = '.';
            }
            else if (ch[i][j] == 'C') {
                dummyCCnt++;
                if (dummyCCnt == 2) ch[i][j] = 'D'; //구분용 도착지
            }
        }
    }
    int ans = INF;
    queue<info> q;
    q.push({sr, sc, 0, -1, 0});
    while (!q.empty())
    {   
        int r = q.front().r;
        int c = q.front().c;
        int status = q.front().status;
        int dir = q.front().dir;
        int cnt = q.front().cnt;


        q.pop();

        if (status == 3) {
            ans = cnt;
            break;
        }

        for (int direction = 0; direction < 4; ++direction) {
            if (direction == dir) continue; // 직전에 들어온 방향와 같은 경우 스킵
            int nr = r + mv[direction][0], nc = c + mv[direction][1];
            if (!isIn(nr, nc) || ch[nr][nc] == '#') continue; // 방문불가

            int new_status = status;
            if (ch[nr][nc] == 'C') new_status |= (1 << 0);
            if (ch[nr][nc] == 'D') new_status |= (1 << 1);

            if (vis[nr][nc][new_status][direction]) continue; // 이미 방문한 상태

            vis[nr][nc][new_status][direction] = true;
            q.push({nr, nc, new_status, direction, cnt+1});
        }   
    }
    cout << (ans == INF ? -1 : ans);
    return 0;
}