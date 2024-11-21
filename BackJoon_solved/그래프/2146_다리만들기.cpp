#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)
using pii = pair<int,int>;
pii operator+(const pii &a, const pii &b) {
    return {a.first+b.first,a.second+b.second};
}
pii mv[4] {{1,0},{-1,0},{0,1},{0,-1}};
int gh[100][100];
int dst[100][100];
int n, cnt = 0;
bool v[100][100];
vector<pii> st_node;

void bfs(pii st) {
    v[st.first][st.second] = true;
    gh[st.first][st.second] = ++cnt;
    queue<pii> q;
    q.push(st);
    st_node.push_back(st);
    while (!q.empty()) {
        pii loc = q.front(); q.pop();
        f(i,0,4) {
            pii nxt = loc+mv[i];
            int nr = nxt.first, nc = nxt.second;
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && !v[nr][nc] && gh[nr][nc]==1) {
                v[nr][nc] = true;
                gh[nr][nc] = cnt;
                q.push({nr,nc});
            }
        }
    }
}

int ans = 1<<30;
void bfs2(int st_island) {
    memset(dst,-1,sizeof(dst));
    queue<pii> q, tp;
    int r = st_node[st_island-1].first, c =st_node[st_island-1].second;
    tp.push({r,c}); q.push({r,c}); dst[r][c]=0;
    while (!tp.empty()) {
        pii loc = tp.front(); tp.pop();
        f(i,0,4) {
            int nr = loc.first+mv[i].first, nc = loc.second+mv[i].second;
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && dst[nr][nc] == -1 && gh[nr][nc]==st_island) {
                dst[nr][nc] = 0;
                q.push({nr,nc});
                tp.push({nr,nc});
            }
        }
    }

    while(!q.empty()) {
        int cr = q.front().first, cc = q.front().second; q.pop();
        f(i,0,4) {
            int nr = cr+mv[i].first, nc = cc+mv[i].second;
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && dst[nr][nc] == -1) {
                if (gh[nr][nc] == 0) {
                    dst[nr][nc] = dst[cr][cc]+1;
                    q.push({nr,nc});
                }
                else {
                    ans = min(ans,dst[cr][cc]);
                    return;
                }
            }
        
    }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i,0,n) f(j,0,n) cin >> gh[i][j];
    f(i,0,n) f(j,0,n) {
        if (gh[i][j] == 1 && !v[i][j]) bfs({i,j});
    }
    f(i,1,cnt+1) bfs2(i);
    cout << ans;
    return 0;

}