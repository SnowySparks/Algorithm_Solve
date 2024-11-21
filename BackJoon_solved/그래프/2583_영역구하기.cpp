#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 200000000
int tb[101][101]; // 0- 빈공간 , INF - 벽, 이외숫자 : 거침

int dr[4]= {-1,1,0,0};
int dc[4]= {0,0,1,-1};
int counts = 0;
vector<int> ans;

int dfs (int r, int c, int M, int N,int check) {
    int cnt = 1;
    for (int i = 0 ; i < 4 ; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nc >= 0 && nr < M && nc < N) {
            if (tb[nr][nc] == 0) {
                tb[nr][nc] = check;
                cnt += dfs(nr, nc, M, N, check);
            }
        }
    }
    return cnt;
}

int bfs (int r, int c, int M, int N, int check) {
    int cnt = 1;
    queue<pair<int ,int> > q;
    q.push({r,c});
    int c_r, c_c , nr, nc;
    while (!q.empty()) {
        c_r = q.front().first; c_c=q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            nr = c_r + dr[i]; nc = c_c+dc[i];
            if (nr >= 0 && nc >= 0 && nr < M && nc < N) {
                if (tb[nr][nc] == 0) {
                    tb[nr][nc] = check;
                    q.push({nr,nc});
                    cnt++;
                }
            }            
        }
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M, N , K; cin >> M >> N >> K;
    int x1, y1, x2, y2;
    //누적합
    while (K--) {
        cin >> x1 >> y1 >> x2 >> y2;
        tb[y1][x1] += 1;
        tb[y2][x2] += 1;
        tb[y1][x2] -= 1;
        tb[y2][x1] -= 1;
    }
    for (int i = 0 ; i < M ; i++) {
        for (int j = 1 ; j < N ; j++) {
            tb[i][j]+=tb[i][j-1];
        } 
    }
    for (int i = 0 ; i < N ; i++) {
        for (int j = 1 ; j < M ; j++) {
            tb[j][i]+=tb[j-1][i];
        } 
    }

    for (int i = 0 ; i <M ; i++) { 
        for (int j = 0 ; j < N ; j++) {
            if (tb[i][j] > 0) tb[i][j]=INF;
        } 
    }
    //dfs or bfs
    for (int i = 0 ; i <M ; i++) { 
        for (int j = 0 ; j < N ; j++) {
            if (tb[i][j] == 0) {
                tb[i][j] = (++counts);
                ans.push_back(bfs(i,j,M,N,counts));
            }
        } 
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto e : ans) {cout << e <<' ';}
    return 0;

}