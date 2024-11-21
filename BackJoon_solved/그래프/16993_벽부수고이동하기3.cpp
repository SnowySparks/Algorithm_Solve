#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef struct _info {
    int r, c, b, t;
} info;

string maps[1000];
int N, M, K;
bool dist[1000][1000][11]; //r , c 몇번 부쉇는가? 

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N ; i++) cin >> maps[i];
    queue<info> q;
    q.push({0,0,0,1});
    dist[0][0][0] = true;
    int answer = -1;
    bool bk;
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int done = q.front().b;
        int tm = q.front().t;
        q.pop();

        if (r == N-1 && c == M -1) {
            answer = tm;
            break;
        }
        bk = false;
        for (int i = 0 ; i < 4 ; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
                if (dist[nr][nc][done] == false && maps[nr][nc]=='0') {
                    dist[nr][nc][done] = true;
                    q.push({nr,nc,done,tm+1});
                }
                if (maps[nr][nc]=='1' && done < K && dist[nr][nc][done+1] == false) {
                    if (tm%2 == 1) {
                        dist[nr][nc][done+1] = true;
                        q.push({nr,nc,done+1,tm+1});
                    }
                    else {
                        bk = true;
                    }
                }
            }
        }
        if (bk) {
            q.push({r,c,done,tm+1});
        }
    }
    cout << answer;
    return 0;
}