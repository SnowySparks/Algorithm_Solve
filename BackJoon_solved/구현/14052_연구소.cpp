#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int max_R, max_C;
int o_map[8][8];
vector<pair<int, int> > combi_walls; //벽 놔둘 곳
vector<pair<int, int> > orig_virus; //원래 바이러스 위치;
vector<bool> visited;
int copy_map[8][8];

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

int answer = 0;

void bfs() {
    queue<pair<int, int> > q;
    int r,c,nr,nc;
    for (auto e : orig_virus) {
        q.push(e);
    }
    while (!q.empty()) {
        r = q.front().first; c = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            nr = r +dr[i]; nc = c +dc[i];
            if (nr >= 0 && nc >= 0 && nr < max_R && nc <max_C) {
                if (copy_map[nr][nc] ==0) {
                    copy_map[nr][nc] = 2;
                    q.push({nr,nc});
                }
            }
        }
    }
}
int check(void) {
    int c = 0;
    for (int i = 0 ; i < max_R ; i++) {
        for (int j = 0 ; j < max_C ; j++) {
            if (copy_map[i][j] == 0) c++;
        }
    }
    return c;
}

void back_track(int cnt, int idx, int N, int M) {
    if (cnt == M) {
        for (int i = 0 ; i <visited.size() ; i++) {
            if (visited[i]) {copy_map[combi_walls[i].first][combi_walls[i].second] = 1;}
        }
        bfs();
        answer = max(answer,check());

        for (int i = 0 ; i < max_R ; i++) {
            for (int j = 0 ; j < max_C ; j++) {
                copy_map[i][j] = o_map[i][j];
            }
        }
        return;
    }
    for (int i = idx ; i <N; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        back_track(cnt+1,idx+1,N,M);
        visited[i] = false;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> max_R >> max_C ;
    for (int i = 0; i < max_R; i++) {
        for (int j = 0; j <max_C; j++) { 
            cin >> o_map[i][j];
            if (o_map[i][j] == 2 ) orig_virus.push_back({i,j});
            else if (o_map[i][j] == 0) {combi_walls.push_back({i,j}); visited.push_back(false);}
            copy_map[i][j] = o_map[i][j];
        }
    }
    back_track(0,0,combi_walls.size(),3);
    cout << answer;
    return 0;
}