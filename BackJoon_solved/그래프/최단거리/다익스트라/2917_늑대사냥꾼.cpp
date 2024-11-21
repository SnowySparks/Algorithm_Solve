#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define f(a,b,c) for (int a=b; a<c;a++)
using pii = pair<int,int>;
int n, m;
string maps[500];
int v[500][500];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
bool dv[500][500];

void clear() {
    f(i,0,n) f(j,0,m) v[i][j] = -1;
}

queue<pii> q;

void xdist() {
    while (!q.empty()) {
        pii loc = q.front(); q.pop();
        f(i,0,4) {
            int nr = loc.first + dr[i], nc = loc.second + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && v[nr][nc] == -1) {
                v[nr][nc] = v[loc.first][loc.second] + 1;
                q.push({nr,nc});
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin >> n >> m;
    pii st, end;
    clear();
    f(i,0,n) {cin >> maps[i];
        f(j,0,m) {
            if (maps[i][j] == 'V') st = {i,j};
            else if (maps[i][j] == 'J') end = {i,j};
            else if (maps[i][j] == '+') {q.push({i,j}); v[i][j] = 0;}
        }
    }
    f(i,0,n) f(j,0,m) dv[i][j] = false;
    xdist();
    priority_queue< pair< int, pii > > pq; // xdist result, points
    pq.push({v[st.first][st.second], st});
    int ans = 1e9;
    dv[st.first][st.second] = true;

    while (!pq.empty()) {
        pii loc = pq.top().second;
        ans = min(ans, pq.top().first);
        pq.pop();
        if (loc == end) break;
        f(i,0,4) {
            int nr = loc.first + dr[i], nc = loc.second + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && !dv[nr][nc] ) {
                dv[nr][nc] = true;
                pq.push({v[nr][nc],{nr,nc}});
            }
        }
    }
    cout << ans;
    return 0;
}