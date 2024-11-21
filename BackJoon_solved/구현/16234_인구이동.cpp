#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define f(a,b,c) for (int a = b ; a < c ; a++)
using namespace std;
int L, R, N;
int dt[50][50];
bool v[50][50];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0,0,1,-1};

void clear(void) {
    f(i,0,N) f(k,0,N) v[i][k] = 0;
}
bool changed = false;

void bfs(int sr, int sc) {
    v[sr][sc] = true;
    int sum = dt[sr][sc];
    vector<pair<int, int> > lst;
    lst.push_back({sr, sc});
    queue<pair<int, int> > q;
    q.push({sr, sc});
    while(!q.empty()) {
        int r = q.front().first, c = q.front().second; q.pop();
        f(i,0,4) {
            int nr = r+dr[i], nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < N && (!v[nr][nc])) {
                int diff = abs(dt[r][c] - dt[nr][nc]);
                if (diff <= R && diff >= L) {
                    v[nr][nc] = true; sum+=dt[nr][nc];
                    changed = true;
                    q.push({nr,nc});
                    lst.push_back({nr,nc});
                }
            }
        }
    }
    sum/=lst.size();
    for (auto e : lst) dt[e.first][e.second] =sum;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L >> R;
    int ans = 0;
    f(i,0,N) f(k,0,N) cin >> dt[i][k];

    while(true) {
        changed = false;
        f(i,0,N) f(k,0,N) if (!v[i][k]) bfs(i,k);
        if (changed) {
            memset(v,false,sizeof(v));
            ans++;
        }
        else break;
    }
    cout << ans;
}