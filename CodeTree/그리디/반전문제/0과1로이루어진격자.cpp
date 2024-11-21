#include <iostream>
#include <cstring>
#define f(a, b, c) for(int a = b; a < c; ++a)
using namespace std;
const int inf = 1e9+7;
int arr[10][10];
int tmp[10][10];
int n;
void tg(int r, int c) {
    f(i, 0, r+1) f(j, 0, c+1) tmp[i][j]^=1;
}

int main() {
    cin >> n;
    char ch;
    f(i, 0, n) {
        f(j, 0, n) {
            cin >> ch;
            arr[i][j] = ch - '0';
        }
    }
    int ans = inf;
    f(st, 0, (1 << n)) {
        int cnt = 0;
        copy(&arr[0][0], &arr[0][0] + 100, &tmp[0][0]);
        //가장 아랫줄

        f(i, 0, n) {
            if (st & (1 << i)) {
                ++cnt;
                tg(n-1, i);
            }
        }

        for (int r = n-2; r >= 0; --r) {
            for (int c = n-1; c >= 0; --c) {
                if (tmp[r][c]) {
                    cnt++;
                    tg(r, c);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (tmp[n-1][i] || tmp[0][i]) {
                cnt = inf;
                break;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans;
    return 0;
}