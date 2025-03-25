#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)
typedef pair<int ,int> pii;
const int mv[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};
int T;
int w, h; // 너비, 높이
char ch[1000][1001];
int fire[1000][1000];
int person[1000][1000];
queue<pii> f, p; //fire, person

bool isIn(int r, int c) {
    if (r < 0 || c < 0 || r >= h || c >= w) return false;
    return true;
}

int pr, pc; //상근이 위치

void init() {
    memset(fire, -1, sizeof(fire));
    memset(person, -1, sizeof(person));
    while (!f.empty()) f.pop();
    while (!p.empty()) p.pop();
}

void input() {
    cin >> w >> h;
    f(i, 0, h) {
        cin >> ch[i];
        f(j, 0, w) {
            if (ch[i][j] == '.') continue;
            if (ch[i][j] == '*') {
                f.push({i, j});
                fire[i][j] = 0;
            }
            else if (ch[i][j] == '@') {
                p.push({i, j});
                person[i][j] = 0;
            }
        }
    }
}

void fire_simulation() {
    // 불 시물레이션
    while (!f.empty())
    {
        auto [r, c] = f.front(); f.pop();
        for (auto &[dr, dc] : mv) {
            int nr = r +dr, nc = c + dc;
            if (isIn(nr, nc) && ch[nr][nc] != '#' && fire[nr][nc] == -1 ) {
                fire[nr][nc] = fire[r][c] + 1;
                f.push({nr, nc});
            }
        }
    }
}

int simulation() {
    while (!p.empty())
    {
        auto [r, c] = p.front(); p.pop();
        for (auto &[dr, dc] : mv) {
            int nr = r +dr, nc = c + dc;
            if (!isIn(nr,nc)) return person[r][c] + 1;
            if (ch[nr][nc] == '#') continue;
            if (person[nr][nc] == -1 && (fire[nr][nc] == -1 || person[r][c] + 1 < fire[nr][nc])) {
                person[nr][nc] = person[r][c] + 1;
                p.push({nr, nc});
            }
        }
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> T;
    while (T--)
    {
        init();
        input();
        fire_simulation();
        int res = simulation();
        if (res == -1) cout << "IMPOSSIBLE\n";
        else cout << res << '\n';
    }
    
    return 0;
}