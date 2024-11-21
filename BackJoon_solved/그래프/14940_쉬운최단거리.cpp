#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
#define f(a,b,c) for (int a = b; a < c; a++)
int n, m;
int mps[1000][1000];
const int inf = 1e9;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin >> n >> m;
    pii st;
    int tmp;
    f(i,0,n) {
        f(j,0,m) {
            cin >> tmp;
            if (tmp == 2) {
                st = {i,j}; mps[i][j] = 0;
            }
            else if (tmp== 1) mps[i][j] = -1;
            else mps[i][j] = inf;
        }
    }

    queue<pii> q; 
    q.push(st);
    while(!q.empty()) {
        pii loc = q.front(); q.pop();
        f(i,0,4) {
            int nr = loc.first + dr[i], nc = loc.second + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && mps[nr][nc] == -1) {
                mps[nr][nc] = mps[loc.first][loc.second] + 1;
                q.push({nr,nc});
            }
        }
    }

    f(i,0,n) {
        f(j,0,m) {
            if (mps[i][j] != inf) cout << mps[i][j] <<' ';
            else cout << 0 << ' ';
        } 
        cout <<'\n';
    }
    return 0;

}