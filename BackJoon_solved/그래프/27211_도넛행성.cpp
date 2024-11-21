#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dt[1000][1000];
int answer = 0;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

void bfs(int r, int c, int mr, int mc) {
    dt[r][c] = 1;
    queue<pair<int, int> > q;
    q.push({r,c});
    int nr,nc;
    while (!q.empty()) {
        int cr = q.front().first, cc = q.front().second; q.pop();
        for (int i = 0; i <4;i++) {
            nr = dr[i] +cr; nc = dc[i] +cc;
            if (nr == mr) nr = 0;
            else if (nr == -1 ) nr = mr -1;
            if (nc == -1) nc = mc-1;
            else if (nc == mc) nc = 0;

            if (dt[nr][nc] == 0) {
                dt[nr][nc] = 1;
                q.push({nr,nc});
            }
        }
    }
    answer++;
}
int main (void) {
    int N, M ; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> dt[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dt[i][j] == 0) bfs(i,j,N,M);
        }
    }
    cout << answer;
    return 0;
}