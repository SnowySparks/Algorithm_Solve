#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[100][100];
int height[100][100];
int high = 0;
int N;

int dr[4] = {1, -1 , 0, 0};
int dc[4] = {0,0,1,-1};

int nr,nc;
int old_r, old_c;

void bfs(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = true;

    while (!q.empty()) {
        old_r = q.front().first;
        old_c = q.front().second;
        q.pop();
            for (int i = 0 ; i < 4 ; i++) {
                nr = old_r + dr[i];
                nc = old_c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
                    if (!visited[nr][nc] && height[nr][nc] > high) {
                        q.push({nr,nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            
        }
}
int main(void) {
    cin >> N;
    int max_height = 0;
    int min_height = 101;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            cin >> height[i][j];
            max_height = max(max_height,height[i][j]);
            min_height = min(min_height,height[i][j]);
        }
    }
    int ans = 0;
    int cnt = 0;
    for (high = min_height-1 ; high <= max_height ; high++) {
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                if (!visited[i][j] && height[i][j] > high) {
                    bfs(i,j);
                    cnt ++;
                }
            }
        }
        ans = max( ans, cnt);
        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                visited[i][j] =false;
            }
        }
        cnt = 0;
    }
    cout << ans;
}

