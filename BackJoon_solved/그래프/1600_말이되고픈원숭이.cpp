#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct info {
    int r,c; //현재 위치
    int k; //몇 번 k번 했는가
    int dist; //현재 이동 횟수;
} INFO;

int k,w,h;
int maps[200][200];
bool visited[200][200][30];
int dr[12] = {1,-1,0,0,1,2,2,1,-1,-2,-2,-1};
int dc[12] = {0,0,1,-1,-2,-1,1,2,-2,-1,1,2};
int nr, nc;

int bfs(int r, int c, int k) {
   INFO a = {r,c,0,0};
   queue<INFO> q;
   q.push(a);
   visited[r][c][0] = true;
   q.push({r,c,0,0});

   while(!q.empty()) {
        a = q.front();
        q.pop();
        if (a.r == h -1 && a.c == w -1) {
            return a.dist;
        }
        for (int i = 0 ; i < 4 ; i++) {
            nr = a.r + dr[i];
            nc = a.c + dc[i];
            if (nr >= 0 && nr < h && nc>=0 && nc < w) {
                if (!visited[nr][nc][a.k] && maps[nr][nc]==0) {
                    visited[nr][nc][a.k] = true;
                    q.push({nr,nc,a.k,a.dist+1});
                }
            }
        }
        if (a.k < k) {
        for (int i = 4 ; i < 12 ; i++) {
            nr = a.r + dr[i];
            nc = a.c + dc[i];

            if (nr >= 0 && nr < h && nc>=0 && nc < w) {
                if (!visited[nr][nc][a.k+1] && maps[nr][nc]==0) {
                    visited[nr][nc][a.k+1] = true;
                    q.push({nr,nc,a.k+1,a.dist+1});
                }
            }
        }
        }
   }
   return -1;
}

int main(void) {
    cin >> k ;
    cin >> w >> h;
    for (int i = 0; i < h ; i++) {
        for (int j = 0; j < w ; j++) {
            cin >> maps[i][j];
        }
    }
    cout << bfs(0,0,k);
    return 0;
}