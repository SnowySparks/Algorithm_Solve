#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#define _inf 987654321
using namespace std;

typedef struct _info {
    int r, c, dir;
} info;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};// 북 동 남 서 (시계방향순서)
int dp[25][25][4]; // r, c, 방향 (인덱스 위 것과 동일) r ,c 까지 가는데 가장 최소 비용, 방향 : 해당 위치 도달할 때 도로 방향
int solution(vector<vector<int>> board) {
    int N = board.size();
    //dp초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j <  N ; j++) {
            for (int k = 0 ; k < 4 ; k++) { dp[i][j][k] = _inf;}
        }
    }
    queue<info> q;
    q.push({0,0,1});
    q.push({0,0,2});
    dp[0][0][1] = 0; dp[0][0][2] = 0; dp[0][0][3] = 0; dp[0][0][0] = 0; // 처음 시작은 남쪽 혹은 동쪽에 직선으로 시작해야함
    while ( !q.empty()) {
        int r = q.front().r, c = q.front().c , dir = q.front().dir; q.pop();
        for (int i = 0; i < 4 ; i++) {//방향, dir 와 같은 방향이면 비용 1, 아니면 비용 5
            int nr = r + dr[i]; int nc = c + dc[i]; int addcost = ( i == dir) ? 1 : 6;
            if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
                if (board[nr][nc] == 0 && dp[nr][nc][i] > dp[r][c][dir] + addcost) {
                    dp[nr][nc][i] = dp[r][c][dir] + addcost;
                    q.push({nr,nc,i});
                }
            }
        }
    }
    return *min_element(dp[N-1][N-1],dp[N-1][N-1]+4) * 100;
}