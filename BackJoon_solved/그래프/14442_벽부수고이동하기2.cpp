#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef struct _info {
    int r, c, b; 
} info;

string maps[1000];
int N, M, K;
int dist[1000][1000][11]; //r , c 몇번 부쉇는가? 

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N ; i++) cin >> maps[i];
    queue<info> q;
    q.push({0,0,0});
    dist[0][0][0] = 1;
    int answer = -1;
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int done = q.front().b;
        q.pop();

        if (r == N-1 && c == M -1) {
            answer = dist[r][c][done];
            break;
        }
        for (int i = 0 ; i < 4 ; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
                if (dist[nr][nc][done] == 0 && maps[nr][nc]=='0') {
                    dist[nr][nc][done] = dist[r][c][done] + 1;
                    q.push({nr,nc,done});
                }
                if (maps[nr][nc]=='1' && done < K && dist[nr][nc][done+1] == 0) {
                    dist[nr][nc][done+1] = dist[r][c][done]+1;
                    q.push({nr,nc,done+1});
                }
            }
        }
    }
    cout << answer;
    return 0;
}