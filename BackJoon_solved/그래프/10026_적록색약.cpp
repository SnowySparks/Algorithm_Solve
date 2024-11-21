#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

string dt[100];
bool visited[100][100];
bool visi1[100][100];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
int rg= 0, b= 0;
int g = 0;
void bfs(int now_r, int now_c,int N) {
    visited[now_r][now_c] = true;
    queue<pair<int,int> > q;
    q.push({now_r, now_c});
    //R or G
    if (dt[now_r][now_c] == 'R' || dt[now_r][now_c] == 'G') {
    while (!q.empty()) {
        int r = q.front().first , c = q.front().second;
        q.pop();
        for (int i = 0; i < 4 ; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
                if (!visited[nr][nc] && (dt[nr][nc] == 'R' || dt[nr][nc] == 'G')) {
                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        }
        rg++; return;
    }
    else {
    while (!q.empty()) {
        int r = q.front().first , c = q.front().second;
        q.pop();
        for (int i = 0; i < 4 ; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
                if (!visited[nr][nc] && (dt[nr][nc] == 'B')) {
                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        }
        b++; return;
    }
}
void bfs1(int now_r, int now_c,int N) {
    visi1[now_r][now_c] = true;
    queue<pair<int,int> > q;
    q.push({now_r, now_c});
    char stat_ = dt[now_r][now_c];
    while (!q.empty()) {
        int r = q.front().first , c = q.front().second;
        q.pop();
        for (int i = 0; i < 4 ; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
                if (!visi1[nr][nc] && (dt[nr][nc] == stat_)) {
                    visi1[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        }
        g++; return;
    
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N ; cin >> N;
    for (int i = 0; i < N ; i++) {
        cin >> dt[i];
    }
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (!visited[i][j]) bfs(i,j,N);
            if (!visi1[i][j]) bfs1(i,j,N);
        }
    }
    cout << g << ' ' << rg+b ; return 0;
}