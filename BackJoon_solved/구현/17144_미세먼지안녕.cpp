#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int uf= -1 , lf =-1; //공기청정기 위치
int maps[50][50];//현 먼지 
int add_maps[50][50];

typedef struct _info {
    int r,c,dirty; //행, 열, 먼지정도
} info;

queue<info> dirty_datas; //5 이상 크기 먼지에 대한 데이터 모음

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

void spread(int tR, int tC) {//먼지퍼짐, tR tC -> 최대 행열 크기
    int r, c,dir, nr ,nc, count;
    while (!dirty_datas.empty()) {
        r = dirty_datas.front().r; c=dirty_datas.front().c; dir = dirty_datas.front().dirty;
        dirty_datas.pop();
        count = 0;
        for (int i = 0 ; i < 4 ; i++) {
            nr = r + dr[i] ; nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < tR && nc <tC) {
                if (nc == 0 && (nr == uf || nr == lf)) continue; //공기청정기가 있는 경우는 스킵
                count++; add_maps[nr][nc] += (dir/5);
            }
        }
        maps[r][c] -= count * (dir/5);
    }
    //map정리
    for (int i = 0 ; i < tR ; i++) {
        for (int j = 0 ; j < tC ; j++) {
            maps[i][j] += add_maps[i][j];
            add_maps[i][j] = 0;
        }
    }
}

//미세먼지 이동;
void move(int tR, int tC) {
    //반시계방향
    
    for (int i = uf-1 ; i >= 1 ; i--) { maps[i][0] = maps[i-1][0]; }
    for (int i = 0 ; i < tC-1; i++) {maps[0][i] = maps[0][i+1];}
    for (int i = 0 ; i < uf ; i++) { maps[i][tC-1] = maps[i+1][tC-1]; }
    for (int i = tC-1; i > 1 ; i--) maps[uf][i] = maps[uf][i-1];
    maps[uf][1] = 0;
    //시계방향
    for (int i = lf+1 ; i < tR-1 ; i++)  maps[i][0] = maps[i+1][0]; 
    for (int i = 0 ; i < tC-1; i++) maps[tR-1][i] = maps[tR-1][i+1];
    for (int i = tR-1; i > lf ; i--) maps[i][tC-1] = maps[i-1][tC-1];
    for (int i = tC-1; i > 1 ; i--) maps[lf][i] = maps[lf][i-1];
    maps[lf][1] = 0;
    
    for (int i = 0 ; i < tR ; i++) {
        for (int j = 0 ; j < tC ; j++) {
            if (maps[i][j] >=5) {dirty_datas.push({i,j,maps[i][j]});}
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int R,C,T; cin >> R >> C >> T;
    for (int i = 0 ; i < R ; i++) {
        for (int j = 0 ; j < C ; j++) {
            cin >> maps[i][j];
            if (maps[i][j] == -1) {
                //공기청정기 위치
                if (uf == -1) uf = i;
                else lf = i;
            }
            else if (maps[i][j]>= 5) {
                dirty_datas.push({i,j,maps[i][j]});
            }
        }
    }
    while (T--) {
    spread(R,C);
    move(R,C); }
    
    int ans = 0;
    for (int i = 0 ; i < R ; i++) {
        for (int j = 0 ; j < C ; j++) {
            if (maps[i][j] > 0) ans+= maps[i][j];
        }
    }
    cout << ans;
    return 0;
}