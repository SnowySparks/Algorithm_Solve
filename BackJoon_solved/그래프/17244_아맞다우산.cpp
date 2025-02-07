#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
const int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
char ch[50][51];
int cnt = 0;
int v[50][50][1<<5];

struct info {
    int r, c, state;
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> m;
    int sr, sc;
    f(i, 0, m) {
        cin >> ch[i];
        f(j, 0, n) {
            if (ch[i][j] == 'X') {
                ch[i][j] = char('0' + cnt);
                ++cnt;
            }
            else if (ch[i][j] == 'S') {
                sr = i; sc = j;
            }
        }
    }

    memset(v, -1, sizeof(v));
    v[sr][sc][0] = 0;
    queue<info> q;
    q.push({sr, sc, 0});
    while (!q.empty())
    {
        auto [r, c, state] = q.front(); q.pop();
        // cout << r << ' ' << c << ' ' << state << '\n';
        if (state == ((1 << cnt) -1) && ch[r][c] == 'E') {
            cout <<v[r][c][state];
            break;
        }

        for (auto [dr, dc] : mv) {
            int nr = r + dr, nc = c + dc;
            // if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (ch[nr][nc] == '#') continue;
            int newState = state;
            if (ch[nr][nc] >= '0' && ch[nr][nc] <= '4') {
                newState |= (1 << int(ch[nr][nc] - '0'));
            }
            if (v[nr][nc][newState] != -1) continue;
            v[nr][nc][newState] = v[r][c][state] + 1;
            q.push({nr, nc, newState});
        }
    }
    return 0;
}