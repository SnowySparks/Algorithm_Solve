#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;

const int mv[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

int n, m;
int pool[52][52];
char ch[52];
bool target[52][52];
bool v[52][52];
int ans = 0;

void simulation() {
    memset(v, 0, sizeof(v));
    queue<pair<int ,int> > q;
    q.push({0, 0});
    v[0][0] = true;

    while (!q.empty())
    {
        auto [r, c] = q.front(); q.pop();
        for (auto [dr, dc] : mv) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr > n+1 || nc > m+1) continue;
            if (v[nr][nc]) continue;
            if (!target[nr][nc]) continue;
            v[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    f(i, 1, n+1) {
        f(j, 1, m+1) {
            if (target[i][j] && !v[i][j]) ++ans;
        }
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f(i, 1, n+1) {
        cin >> (ch + 1);
        f(j, 1, m+1) {
            pool[i][j] = ch[j] - '0';
        }
    }

    // 물 높이 -> 한칸한칸 쌓아두기
    f(h, 1, 10) {
        memset(target, 0, sizeof(target));
        // 높이가 h미만인 모든 칸 탐색
        f(i, 1, n+1) {
            f(j, 1, m+1) {
                if (pool[i][j] < h) target[i][j] = true;
            }
        }

        // 곁다리
        f(i, 0, n+2) {
            target[i][0] = target[i][m+1] = true;
        }
        f(i, 0, m+2) {
            target[0][i] = target[n+1][i] = true;
        }


        // 한칸한칸 쌓아둘 때 바깥으로 흘러나가는지 시물레이션
        simulation();
    }
    cout << ans;
    return 0;
}
