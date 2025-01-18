#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
int arr[10][10];
const int INF = 1e9 + 7;
int ans = 1e9 + 7;
int leftPaper[6] = {0, 5, 5, 5, 5, 5};

bool isAllOne(int r, int c, int len) {
    if (r+len > 10 || c + len > 10) return false;
    for (int i = r; i < (r + len); ++i) {
        for (int j = c; j < (c + len); ++j) {
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

bool isAllZero() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (arr[i][j] == 1) return false;
        }
    }
    return true;
}

void setIn(int r, int c, int len, int res) {
    for (int i = r; i < (r + len); ++i) {
        for (int j = c; j < (c + len); ++j) {
            arr[i][j]=res;
        }
    }
    return;
}

void dfs(int r, int c, int cnt) {
    if (ans <= cnt) return; //조기종료
    while (arr[r][c] == 0) {
        c++;
        if (c == 10) {
            r++;
            if (r>=10) { //탐색 끝.
                ans = min(ans, cnt);
                return;
            }
            c=0;
        }
    }
    // 완탐이지만 그래도 가능하면 큰 색종이 쓰는 것이 좋으니 큰것 부터 계산
    for (int len = 5; len >= 1; --len) {
        if (leftPaper[len] > 0 && isAllOne(r, c, len)) {
            // 색종이 붙인 공간 0 및 색종이 사용 처리
            leftPaper[len]--;
            setIn(r, c, len, 0);
            dfs(r, c, cnt+1);
            // 롤백
            leftPaper[len]++;
            setIn(r, c, len, 1);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> arr[i][j];
        }
    }
    dfs(0,0,0);
    cout << (ans == INF ? -1 : ans);
    
    return 0;   
}