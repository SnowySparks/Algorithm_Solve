#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)

int mv[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n, m, t = 0, cnt = 0;

short gh[100][100]; // 2 : outair, 0 : inair: 1:cheese
bool v[100][100];

void outair(void) {
    memset(v,false,sizeof(v));
    gh[0][0] = 2; v[0][0] = true;
    queue<pair<int,int> > q; q.push({0,0});
    while (!q.empty()) {
        int cr = q.front().first, cc=q.front().second; q.pop();
        f(i,0,4) {
            int nr = cr+mv[i][0], nc = cc+mv[i][1];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && !v[nr][nc]) {
                if (gh[nr][nc] == 0) {
                    gh[nr][nc] = 2;
                    v[nr][nc] = true;
                    q.push({nr,nc});
                }
                else if (gh[nr][nc]==2) {
                    v[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
    }
}


int outcnt(int r, int c) { //해당 위치가 치즈인 경우에 치즈바깥 공기접촉면 카운팅
    int res = 0;
    f(i,0,4) {
        int nr = r+mv[i][0], nc =  c+mv[i][1];
        if (gh[nr][nc] == 2) res++;
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f(i,0,n) f(k,0,m) {cin >> gh[i][k]; 
        if (gh[i][k]==1) cnt++;}
    while (true) {
        outair();
        f(i,1,n-1) f(j,1,m-1) {
            if (gh[i][j]==1 && outcnt(i,j)>=2) {
                cnt--;
                gh[i][j]=0;
            }
        }
        ++t;
        if (cnt == 0) {
            cout <<t;
            break;
        }
    }
    return 0;
}