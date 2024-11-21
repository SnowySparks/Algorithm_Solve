#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C;
int dr[] {-1, 0, 1};
string inp[10000];
bool fd = false;

// 그리디 + dfs
// 가능하면 가장 위쪽 혹은 가장 아래쪽에 둬야함
// 위쪽부터 탐색할 꺼니 가장 위쪽 (가능한 가장 위 행에)
// 가능한 위쪽 부분우선적탐색
// 만약 연결이 되었으면 그 순간 어느 외부 영역에 탐색 성공했다고 띄우고
// 그 이후 모든 dfs 탐색은 무조건 false처리 되어야함

// 다음주자에게 그 길을 선택하지 말라는 의미입니다. (pruning)
// '이 길로 내가 가봤는데 나중에 막다른길이 나오더라고. or 이미 차지했어 그러니깐 넌 일로 가지마' 라는 의미입니다.

bool dfs(int r, int c) {
    if (fd) return false;
    if (c == C-1) {
        if (inp[r][c] == '.' && fd==false) {
            inp[r][c] = 'x';
            inp[r][c] = true;
            fd=true;
            return true;
        }
        else return false;
    }
    inp[r][c]='x';
    for (int i = 0; i < 3; ++i) {
        int nr = r + dr[i];
        if (nr >= 0 && nr < R && inp[nr][c+1] =='.') {
            if (dfs(nr,c+1)) {return true;}
        }
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; ++i) cin >> inp[i];
    int res =0;
    for (int i = 0; i < R; ++i) {
        fd = false;
        if (dfs(i,0)) ++res;
    }
    // for (int i = 0; i < R; ++i) {
    //     cout << inp[i] <<'\n';
    // }
    cout << res;
    return 0;
}