#include <iostream>
#include <vector>
#include <queue>
#define f(a,b,c) for(int a=b;a<c;a++)
using namespace std;

int w,h;

short gh[50][50];
bool v[50][50];

int dr[] {1,-1,0,0,1,1,-1,-1};
int dc[] {0,0,1,-1,1,-1,1,-1};

void clear(int r, int c) {
    f(i,0,r) f(k,0,c) v[i][k] = false;
}

void bfs(int sr, int sc) {
    v[sr][sc] = true;
    queue<pair<int, int> > q;
    q.push({sr,sc});

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second; q.pop();
        f(i,0,8) {
            int nr = r + dr[i] , nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < h && nc < w && !v[nr][nc] && gh[nr][nc]==1) {
                v[nr][nc] = true; q.push({nr,nc});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (1) {
        cin >> w>> h;
        if (w ==0 && h == 0) break;
        int ans = 0;
        f(i,0,h) f(k,0,w) cin >> gh[i][k];
        f(i,0,h) f(k,0,w) {
            if (!v[i][k] && gh[i][k] == 1) {
                ans++;
                bfs(i,k);
            } 
        }
        cout << ans << '\n';
        clear(h,w);
    }
    return 0;
}