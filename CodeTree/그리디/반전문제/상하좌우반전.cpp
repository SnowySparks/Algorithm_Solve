#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define f(a, b, c) for(int a=b;a<c;++a)
const int inf = 1e9+7;
int n;
int m[100][100], copy_m[100][100];

int mv[5][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};

void tg(int r, int c) {
    for (auto &[dr, dc] : mv) {
        int nr = r + dr, nc = c + dc;
        if (nr < 0 || nr >=n || nc < 0 || nc >= n) continue;
        copy_m[nr][nc] ^= 1;
    }
}

void reset() {
    f(i, 0, n) f(j,0, n) copy_m[i][j] = m[i][j];
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) {
        f(j, 0, n) {
            cin >> m[i][j];
        }
    }

    int ans = inf;
    int cnt = 0;
    reset();
    f(r, 1, n) {
        f(c, 0, n) {
            if (!copy_m[r-1][c]) {
                tg(r, c);
                ++cnt;
            }
        }
    }
    f(i, 0, n) if(!copy_m[n-1][i]) cnt = inf;
    ans = min(ans, cnt);
    cout << (ans == inf ? -1 : ans);
    return 0;
}

//  첫 번째 행을 제외한 위치에 있는 칸을 누르는 것이 가능하고, 
//  특정 칸을 누르게 되면 해당 칸에 있는 숫자 뿐 아니라 바로 상하좌우 인접한 칸에 있는 숫자 까지도 전부 반전