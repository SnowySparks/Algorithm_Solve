#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

#define inf 10000001

bool visited[1001][1001][2]; // 행, 열, 벽부술수 있는가?(1 : 가능, 0 : 불가능)
int dist[1001][1001][2] ; //1,1 에서 n,m까지 이동 거리.
vector<string> dt(1001);
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
int n,m; // 행, 열 크기

int r, c;
int nr, nc;

void bfs(int rc, int lc) { //시작점 기준
    dist[rc][lc][1] = 1;
    visited[rc][lc][true] = true; //시작점 방문 처리
    int r ,c;
    bool wall;
    int nr, nc;
    queue<tuple<int,int,bool>> q;
    q.push({rc,lc,true});

    while(!q.empty()) {
        tie(r,c,wall) = q.front();
        q.pop();
        for (int i = 0 ; i <  4 ; i++) {
            nr = r + dx[i];
            nc = c + dy[i];

            if (nr >= 1 && nr <= n && nc >=1 && nc <= m) {//크기초과여부
                //갈수 없는 길이나, 아직 벽을 안 부순 상태
                //단 1회만 가능하니, 방문 여부는 신경 안써도 됨.
                if (dt[nr-1][nc-1] == '1' && wall == true) {
                    visited[nr][nc][false] = true;
                    q.push({nr,nc,false});
                    //거리 갱신
                    dist[nr][nc][0] = dist[r][c][wall]+1;
                }
                //갈 수 있고, 방문 안했을 경우.
                else if (dt[nr-1][nc-1] == '0' && !visited[nr][nc][wall]) {
                    visited[nr][nc][wall] = true;
                    q.push({nr,nc,wall});
                     //거리 갱신
                     dist[nr][nc][wall] = dist[r][c][wall] + 1;
                                    
                }
            }

        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i<n ;i++) {
        cin >> dt[i];
    }
    bfs(1,1); 
    
    if (dist[n][m][0] == 0 && dist[n][m][1] == 0) cout << -1;
    else if (dist[n][m][0] != 0 && dist[n][m][1] != 0) cout << min(dist[n][m][0],dist[n][m][1]);
    else cout << max(dist[n][m][0],dist[n][m][1]);

}