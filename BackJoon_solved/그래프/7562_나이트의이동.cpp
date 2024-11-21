#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int maps[300][300];
bool visited[300][300];
int n,cnt;


int dx[] = {1,1,2,2,-1,-1,-2,-2};
int dy[] = {2,-2,1,-1,2,-2,1,-1};

void bfs (int sx, int sy, int ex, int ey) {
    bool end= false;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    visited[sx][sy] = true;
    int nx,ny;

    while (!q.empty()) {
        auto e = q.front();
        q.pop();
        if (e.first == ex && e.second == ey) {
            break;
        }

        for (int i=0;i<8;i++) {
            nx = e.first + dx[i];
            ny = e.second + dy[i];


            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if (visited[nx][ny]==false) { 
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                    maps[nx][ny] = maps[e.first][e.second] +1;
                    if (nx == ex && ny == ey) {
                        end = true;
                        break;
                    }
                }
            }
        }
        if (end ==true) {
            break;
        }
    }
}


int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    int x,y,ex,ey;

    while (N--) {
        cin >> n;
        cin >> x >> y;
        cin >> ex >> ey;
        bfs(x,y,ex,ey);
        cout << maps[ex][ey] <<'\n';

        for (int i=0 ; i< n ; i++) {
            for (int j=0 ; j< n ; j++)  {
                visited[i][j] = false;
                maps[i][j] = 0;
            }
        }    
    }

    return 0;
}