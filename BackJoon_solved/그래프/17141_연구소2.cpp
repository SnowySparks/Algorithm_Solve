#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define _inf 101
using namespace std;
int gh[50][50];
bool visited[50][50];
int airsize = 0; //0 ,2 의 개수
int N, M; //사이즈, 놓을 바이러스 크기
int answer = _inf;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

vector<pair<int, int> > vloc; //바이러스 놓을 위치
vector<bool> bv; //백트래킹

int bfs(void) {
    queue<pair<int, int> > q;
    int nowairs = airsize - M;
    if (nowairs == 0) return -1;
    int time = 0;
    for (int i = 0 ; i  < vloc.size() ; i++) {
        if (bv[i]) {
            visited[vloc[i].first][vloc[i].second] = true;
            q.push(vloc[i]);
        }
    }
    int synctime = q.size(); //1초내 처리해야 할 데이터 크기
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        synctime--;

        for (int i = 0 ; i < 4 ; i++) {
            int nr = p.first + dr[i]; int nc = p.second + dc[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < N && gh[nr][nc]!=1 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                nowairs--;
                q.push({nr,nc});
            }
        }
        if (synctime == 0 && nowairs > 0) {time++; synctime = q.size();}
        if (time > answer) break;
    }
    //리셋
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            visited[i][j] = false;
        }
    }
    if (nowairs <= 0) return time;
    else return _inf;
}

void back_track(int cnt, int idx, int n, int m) {
    if (cnt == m) {
        answer = min(answer, bfs());
    }

    for (int i = idx ; i < n ; i++) {
        if (bv[i]) continue;
        bv[i] = true;
        back_track(cnt+1,idx+1,n,m);
        bv[i] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> gh[i][j];
            if (gh[i][j] == 2) {vloc.push_back({i,j}); bv.push_back(false);}
            if (gh[i][j] != 1) airsize++;
        }
    }
    back_track(0,0,vloc.size(),M);
    if (answer >= _inf) cout << -1;
    else cout << answer+1;
    return 0;
}