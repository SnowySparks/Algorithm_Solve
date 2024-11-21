#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)
int N,M;
string st[1000];
int dt[1000][1000];
bool v[1000][1000];
int dr[4] {0,0,1,-1};
int dc[4] {1,-1,0,0};
int dat[1000001];
int cnt = 0;

void bfs(int sr, int sc) {
    int sz = 1;
    v[sr][sc] = true;
    dt[sr][sc] = ++cnt;
    queue<pair<int, int> > q;
    q.push({sr,sc});

    while(!q.empty()) {
        int r = q.front().first, c =q.front().second; q.pop();
        f(i,0,4) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < M && !v[nr][nc] && st[nr][nc]=='0') {
                dt[nr][nc] = cnt;
                v[nr][nc] = true;
                sz++;
                q.push({nr,nc});
            }
        }
    }
    dat[cnt] = sz;
}

int connect(int sr, int sc) {
    if (st[sr][sc] == '0') return 0;
    int res = 1;
    vector<int> dup;
    f(i,0,4) {
        int nr = sr + dr[i], nc = sc + dc[i];
        if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
           int p= dt[nr][nc]; 
           if (find(dup.begin(), dup.end(), p) != dup.end()) continue;
           res+=dat[p]; dup.push_back(p);
        }
    }
    return res;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    f(i,0,N) cin >> st[i];
    dat[0] = 0;
    f(i,0,N) f(k,0,M) {
        if (st[i][k] == '1') continue;
        else if (!v[i][k]) bfs(i,k);
    }
    f(i,0,N){ f(k,0,M) {cout << connect(i,k)%10;} cout<<'\n';}
    return 0;
}