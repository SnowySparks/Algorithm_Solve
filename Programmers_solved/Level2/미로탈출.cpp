#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef struct _info {
    int r, c, move;
    bool pressed;
} info;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0,0,1,-1};
int N, M;
bool visited[2][100][100];
int answer = -1;
pair<int, int> s, e;

void bfs(vector<string> &maps) {
    queue<info> q;
    q.push({s.first, s.second, 0, false});
    visited[0][s.first][s.second] = true;
    while( !q.empty() ) {
        info t = q.front();
        q.pop();

        if (t.pressed && t.r == e.first && t.c == e.second) {
            answer = t.move;
            return;
        }

        for ( int i = 0; i < 4 ; i++) {
            int nr = t.r + dr[i], nc = t.c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
                if (!visited[t.pressed][nr][nc] ) {

                    if (maps[nr][nc] == 'O' || maps[nr][nc] == 'E' || maps[nr][nc] == 'S') {
                        visited[t.pressed][nr][nc] = true;
                        q.push( {nr,nc,t.move+1,t.pressed} );
                    }
                    else if (maps[nr][nc] == 'L') {
                        visited[t.pressed][nr][nc] = true;
                        q.push( {nr,nc,t.move+1,true} );
                    }
                }
            }
        }
    }
}

int solution(vector<string> maps) {
    N = maps.size(); M = maps[0].size();
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maps[i][j] == 'S') s = {i,j};
            else if (maps[i][j] == 'E') e = {i,j};
        }
    }
    bfs(maps);
    return answer;
}