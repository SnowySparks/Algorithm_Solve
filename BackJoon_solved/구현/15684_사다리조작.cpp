#include <iostream>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;++a)
int N, M, H;

int ans = 4;
bool ladder[32][12]; //가로줄 위치값, 세로줄 위치값, [a][b] = True이건 해당 a위치에 b, b+1 세로줄에 연결되어있음 의미
bool fd = false;

int go(int x) { //시작점이 x일때 끝점이 어디지?
    int nowh = 1;
    while (nowh <= H)
    {
        if (ladder[nowh][x]) ++x;
        else if (ladder[nowh][x-1]) --x;
        ++nowh;
    }
    return x;
}

bool check() { //전체 탐색하고 하나라도 원래 자리 안가면 False
    f(i, 1, N+1) {
        if (go(i) != i) return false;
    }
    return true;
}

void back_track(int nowh, int nowl, int cnt, int maxcnt) { //backtracking
    if (fd) return;
    if (maxcnt == cnt) { // 확인하고 맞으면 그 즉시 모든 트랙킹 종료
        if (check()) {
            ans = cnt;
            fd = true;
        }
        return;
    }
    f(h, nowh, H+1) { // 왼쪽 상단 부분부터 오른쪽이로 탐색,
        int locl= (h == nowh ? nowl : 1); //처음 탐색 높이 위치가 호출된 함수값과 같으면, 굳이 1부터 다시 탐색 할 필요가 x
        f(l, locl, N) {
            if (ladder[h][l-1] || ladder[h][l] || ladder[h][l+1]) continue; //사다리 연결 조건.
            //현재 l -> l+1 설치할려면 l-1 -> l, l+1 -> l+2도 설치가 되어 있으면 안됨...
            ladder[h][l] = true;
            back_track(h, l+1, cnt+1, maxcnt);
            if (fd) return;
            ladder[h][l] = false;
        }
    }
    return;
}

int main(void) { 
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> H;
    f(i, 0, M) {
        int a, b; cin >> a >> b;
        ladder[a][b] = true;
    }
    f(i, 0, 4) back_track(1, 1, 0, i);
    cout << (ans > 3 ? -1 : ans);
    return 0;

}