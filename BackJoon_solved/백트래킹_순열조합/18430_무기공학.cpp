#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)

int arr[5][5], n, m;
bool used[5][5];
int ans = 0;
bool isIn(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m) return false;
    return true;
}

int target[4][3][2] = {
    {
        {0, -1},
        {0, 0,},
        {1, 0}
    },
    {
        {0, -1},
        {0, 0,},
        {-1, 0}
    },
    {
        {-1, 0},
        {0, 0,},
        {0, 1}
    },
    {
        {1, 0},
        {0, 0,},
        {0, 1}
    },
};

bool checkAvailabe(int cr, int cc, int tg) {
    f(i, 0, 3) {
        int r = cr + target[tg][i][0];
        int c = cc + target[tg][i][1];

        if (!isIn(r, c) || used[r][c]) return false;
    }
    return true;
}

void setUsed(int cr, int cc, int tg, bool setVal) {
    f(i, 0, 3) {
        int r = cr + target[tg][i][0];
        int c = cc + target[tg][i][1];
        used[r][c] = setVal;
    }
}

int calScore(int cr, int cc, int tg) {
    int res = 0;
    f(i, 0, 3) {
        int r = cr + target[tg][i][0];
        int c = cc + target[tg][i][1];
        res += (i == 1 ? 2*arr[r][c] : arr[r][c]);
    }
    return res;
}

void dfs(int r, int c, int total) {
    ans = max(ans, total);
    f(i, r, n) {
        int j = (i == r ? c : 0);
        for (;j < m; ++j) {

            f(tg, 0, 4) {
                if (checkAvailabe(i, j, tg)) {
                    setUsed(i, j, tg, true);
                    dfs(i, j, total + calScore(i, j, tg));
                    setUsed(i, j, tg, false);
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f(i, 0, n) f(j, 0, m) cin >> arr[i][j];
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}