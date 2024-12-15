#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;

char ch[102][102]; //input
int dist[3][102][102]; // 거리측정
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int H, W;
pair<int, int> loc[3] ={{0, 0}, {0, 0}, {0, 0}}; // 상근이(밖에)[0], 죄수[1], 죄수[2];
const int inf = 1e8 + 7;

deque<pair<int ,int> > dq;

bool isIn(int r, int c) {
    if (r < 0 || c < 0 || r > H+1 || c > W+1) return false;
    return true;
}


 // w : 너비 (열크기). h : 높이 (행크기)
void input() {
    cin >> H >> W;
    int prisonerCnt = 0;

    for (int i = 1; i <= H; ++i) {
        cin >> (ch[i] + 1);
        for (int j = 1; j <= W; ++j) {
            if (ch[i][j] == '$') {
                ++prisonerCnt;
                loc[prisonerCnt].first = i;
                loc[prisonerCnt].second = j;
                ch[i][j] = '.';
            }
        }
    }
    for (int i = 0; i <= W+1; ++i) {
        ch[0][i] = '.';
        ch[H+1][i] ='.';
    }

    for (int i = 0; i <=H+1; ++i) {
        ch[i][0] = '.';
        ch[i][W+1] = '.';
    }

    memset(dist, -1, sizeof(dist));
}



void simulation(int locIdx) {
    dq.clear();
    // 각 위치마다의 시작점을 기준으로 0-1 BFS 시작
    dq.push_back({loc[locIdx].first, loc[locIdx].second});
    dist[locIdx][loc[locIdx].first][loc[locIdx].second] = 0;
    int r, c;
    while (!dq.empty())
    {   
        tie(r, c) = dq.front();
        dq.pop_front();

        for (auto [dr, dc] : mv) {
            int nr = r + dr, nc = c + dc;
            if (isIn(nr, nc)  &&  ch[nr][nc] != '*' && dist[locIdx][nr][nc] == -1) {
                int curCnt = dist[locIdx][r][c];
                if (ch[nr][nc] == '#') {
                    dist[locIdx][nr][nc] = curCnt + 1;
                    dq.push_back({nr, nc});
                }
                else {
                    dist[locIdx][nr][nc] = curCnt;
                    dq.push_front({nr, nc});
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int T; cin >> T;
    while (T--)
    {
        input();
        for (int i = 0; i < 3; ++i) simulation(i);
        int ans = inf;
        for (int i = 0; i <= H+1; ++i) {
            for (int j = 0; j <= W+1; ++j) {
                if (ch[i][j] == '*') continue; // 갈 수 없는 벽
                else if(dist[0][i][j]==-1 || dist[1][i][j]==-1 || dist[2][i][j]==-1) continue; // 절대로 3명이 전부 못 모이는 곳
                // 이 이후로는 만남이 가능한 위치

                // 문이 있는 위치 -> 한번만 열면 되기에 -2를 해서 중복 제거
                else if (ch[i][j] == '#') ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] -2);
                else ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j]);
            }
        }
        cout << ans << '\n';
    }
    

    return 0;
}

// 원리
// 문이 있으면 가중치 1, 빈 공간이면 0 이런 형식이기에 0-1 BFS 사용하기에 최적
// 문제에서는 외부인이 직접 안에 들어가서 죄수1, 죄수2 를 구하러 가는데 드는 문 여는 개수(가중치) 의 최소값

// 다른 관점으로 보면 좌수 1, 2도 문을 열 수 있고 이동한다고 생각을 해 두면
// 결국 외부인 - 죄수1, 죄수2 3명 다 만날 수 있는 어느 한 지점에서의 가중치의 총합 들 중 최소값이 답이 됨
// 단 문이 있는 위치는 누군가 문을 열면 그 이후 나머지 2명분에 대한 중복 계산 처리를 위해서 -2를 함