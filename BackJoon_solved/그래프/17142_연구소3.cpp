#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define f(a,b,c) for(int a = b; a < c; a++)
using namespace std;
int N, M;
int dt[50][50];
int v[50][50];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int airarea = 0;
const int inf = 3123;
vector<pair<int, int> > unvirus;
vector<pair<int, int> > first_active;
int ans = inf;
int bfs(void) {
    int infarea = 0;
    int mtime = 0;
    memset(v, -1, sizeof(v));
    queue<pair<int, int> > q;
    for (auto e : first_active) {q.push(e), v[e.first][e.second] = 0;}
    while(!q.empty()) {
        int r = q.front().first , c = q.front().second; q.pop();
        f(i,0,4) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < N && v[nr][nc] == -1 && dt[nr][nc] != 1) {
                v[nr][nc] = v[r][c]+1;
                if (dt[nr][nc] == 0) {infarea++; mtime =v[nr][nc];}
                q.push({nr,nc});
            }   
        }
    }
    
    if (infarea == airarea) return mtime;
    else return inf;
}

void backtrack(int cnt, int loc, int nN, int nM) {
    if (cnt == nM) {
        ans = min(ans, bfs()); return;
    }
    f(i,loc,nN) {
        first_active.push_back(unvirus[i]);
        backtrack(cnt+1, loc+1, nN, nM);
        first_active.pop_back();
        return;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    f(i,0,N) f(k,0,N) {
        cin >> dt[i][k];
        if (dt[i][k] == 0) airarea++;
        else if (dt[i][k] == 2) unvirus.push_back({i,k});
    }
    backtrack(0,0,unvirus.size(), M);
    if (ans == inf) cout << "-1";
    else cout << ans;
    return 0;
}