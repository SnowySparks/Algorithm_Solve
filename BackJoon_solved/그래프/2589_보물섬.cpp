#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define inf 10000000
using namespace std;

int dt[50][50];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
int R, C;

int answer = 0;

void init() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (dt[i][j] != inf) dt[i][j] = -1;
        }
    }
}

void bfs(int now_r, int now_c) {
    dt[now_r][now_c] = 0;
    queue<pair<int ,int >  > q;
    q.push({now_r,now_c});
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        answer = max(answer, dt[r][c]);
        for (int i = 0 ; i < 4; i++) {
            int nr = r + dr[i]; int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < R && nc < C) {
                if (dt[nr][nc] == -1) {
                    dt[nr][nc] = dt[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin >> R >> C;
    string inp;
    for (int i = 0; i < R; i++) {
        cin >> inp;
        for (int j = 0; j < C; j++) {
            dt[i][j] = (inp[j] == 'W' ? inf : -1);
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (dt[i][j] != inf) {
                bfs(i,j);
                init();
            }
        }
    }
    cout <<answer; return 0;
}