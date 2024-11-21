#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define f(a,b,c) for(int a=b;a<c;a++)
using namespace std;

int gh[102][102];
bool v[102][102];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

int R, C;

void spread() {
    queue<pair<int, int> > q;
    v[0][0] = true;
    q.push({0,0});
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second; q.pop();
        f(i,0,4) {
            int nr = r + dr[i] , nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < R+2 && nc < C+2 && !v[nr][nc] && gh[nr][nc]!=1) {
                v[nr][nc] = true; q.push({nr,nc}); gh[nr][nc] = 2;
            }
        }
    }
}

bool out(int r, int c) {
    f(i,0,4) {
        int nr = r + dr[i], nc = c + dc[i];
        if ( nr >= 0 && nr< R+2 && nc >= 0 && nc < C+2 && gh[nr][nc]==2) return true;
    }
    return false;
}

queue<pair <int, int> > rp;
int bfs(int sr, int sc) {
    if (gh[sr][sc] !=1 || v[sr][sc]) return 0;
    int sz = 1;
    v[sr][sc] = true;
    if (out(sr,sc)) rp.push({sr,sc});
    queue<pair<int, int> > q;
    q.push({sr,sc});

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second; q.pop();
        f(i,0,4) {
            int nr = r + dr[i] , nc = c + dc[i];
            if (nr >= 1 && nc >= 1 && nr < R+1 && nc < C+1 && !v[nr][nc] && gh[nr][nc]==1) {
                v[nr][nc] = true; q.push({nr,nc}); sz++;
                if (out(nr,nc)) rp.push({nr,nc});
            }
        }
    }
    return sz;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int time = 0;
    int m_size = 1E6;
    cin >> R>> C;
    f(i,0,R+2) {gh[0][i] = 2; gh[C+1][i] = 2;}
    f(i,0,C+2) {gh[i][0] = 2; gh[i][R+1] = 2;}
    f(i,1,R+1) f(k,1,C+1) cin >> gh[i][k];

    while (1) {
        int sz = 0;
        spread();
        f(i,1,R+1) f(k,1,C+1) sz+=bfs(i,k);
        if (sz == 0) break;
        m_size = min(m_size,sz);
        time++;
        memset(v,0,sizeof(v));
        while (!rp.empty()) {
            gh[rp.front().first][rp.front().second] = 0;
            rp.pop();
        }
    }
    cout << time << '\n' << m_size;
    return 0;
}