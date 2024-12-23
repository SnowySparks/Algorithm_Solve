#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
const int INF = 1e9 + 7;
const int mv[5][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {0, 0}};

int input[18][18]; // 실제 입력 값
int state[18][18]; // 시물레이션

bool isIn(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n ) return false;
    return true;
}

void toggle(int r, int c) {
    for (auto [dr, dc] : mv) {
        int nr = r + dr, nc = c + dc;
        if (isIn(nr, nc)) {
            state[nr][nc]^=1;
        }
    }
}

bool isAllOff() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (state[i][j] == 1) return false;
        }
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> input[i][j];
        }
    }
    int ans = INF;

    // Bitmasking
    for (int bit = 0; bit < (1 << n); ++bit) {
        memcpy(state, input, sizeof(state));
        int cnt = 0;
        // 첫줄에 대해서는 bit마스킹에 따른 버튼 입력
        for (int i = 0; i < n; ++i ) {
            if (bit & (1 << i)) {
                ++cnt;
                toggle(0, i);
            }
        }

        // 이후 두번째 열부터는 (r=1), 그 윗줄(r-1)이 불이 켜저 있는 경우 r,c 스위치 누르기

        for (int r = 1; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (state[r-1][c]) {
                    toggle(r, c);
                    ++cnt;
                }
            }
        }
        if (isAllOff()) {
            ans = min(ans, cnt);
        }
    }
    cout << (ans == INF ? -1 : ans);

    return 0;
}