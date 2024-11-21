#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#define F(a,b,c) for (int a = b; a < c; a++)
using namespace std;
const int inf = 1E8;
int N, M, K;
string dt[1000];
bool p[1000][1000][4];
int dr[] = {1, 0, 0, -1, 0};
int dc[] = {0, 1, -1, 0, 0};
typedef struct _info {
    int r, c, dir, move;
    _info(int a1, int a2) : r(a1), c(a2), dir(-1), move(0) {}
    _info(int a1, int a2, int a3, int a4) : r(a1), c(a2), dir(a3), move(a4) {}
} info;
int num(int r, int c) {
    if (dt[r][c] == 'H' || dt[r][c] =='S') return 0;
    return dt[r][c] - '0'; }
int cal(int bd, int cr, int cc, int nd) {
    return num(cr + dr[bd], cc + dc[bd]) + num(cr, cc) + num(cr + dr[nd], cc + dc[nd]);}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    queue<info> q;
    F(i,0,N) {
        cin >> dt[i];
        F(k,0,M) {
            if(dt[i][k] == 'S') q.push(_info(i,k)); } }
    int answer = -1;
    while(!q.empty()) {
        info tp = q.front(); q.pop();
        if (dt[tp.r][tp.c] == 'H') {
            answer = tp.move; break;
        }
        else {
            F(i,0,4) {
                if ( i == tp.dir) continue;
                int nr = tp.r + dr[i], nc = tp.c + dc[i];
                if (nr >= 0 && nr < N && nc >= 0 && nc < M && dt[nr][nc]!='X') {
                    int sum = cal(tp.dir, tp.r, tp.c, i);
                    if (sum > K || p[nr][nc][3-i]) continue;
                    p[nr][nc][3-i] = true;
                    q.push(_info(nr,nc,3-i,tp.move+1));
                }
            }
        }
    }
    cout << answer; return 0;
}