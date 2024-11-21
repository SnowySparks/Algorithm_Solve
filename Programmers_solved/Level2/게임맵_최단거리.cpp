#include<vector>
#include<queue>
#include<algorithm>
#include <iostream>
using namespace std;

bool visited[100][100];
int dist[100][100];

int dx[4]= {0,0,1,-1};
int dy[4] ={1,-1,0,0};

void bfs(int x, int y ,int n,int m, const vector<vector<int>> &maps) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    int a,b,nx,ny;
    while (!q.empty()) {
        a=q.front().first;
        b=q.front().second;

        q.pop();
        for (int i=0; i<4; i++) {
            nx = a + dx[i];
            ny = b + dy[i];

            if (nx >=0 && nx < n && ny >=0 && ny < m) {
                if ( visited[nx][ny]==false && maps[nx][ny] ==1) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[a][b] + 1;
                }
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int n = maps.size(), m = maps[0].size();
    for (int i= 0 ;i < n ;i++) {
        for (int j= 0 ;j < m ;j++) {
            visited[i][j] =false;
            dist[i][j] =0;
        }
    }

    bfs(0,0,n,m,maps);
    return visited[n-1][m-1] ? dist[n-1][m-1] +1 : -1;
}