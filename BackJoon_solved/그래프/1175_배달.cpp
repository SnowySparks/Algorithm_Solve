#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define INF 200000000
string dt[50];
int mr,mc;
typedef struct _state {
    int r, c, d;
} state;

int maps[50][50];

void init(void) {
    for (int i = 0 ; i < mr ; i++) {
        for (int j = 0 ; j < mc ; j++) {
            if (maps[i][j] < INF ) maps[i][j] = 0;
        }
    }
}

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

vector<int> bfs (int sr, int sc, int loc) {
    maps[sr][sc] = 1;
    queue<_state> q;
    q.push({sr,sc,loc});
    int r,c,d,nr,nc;
    while (!q.empty()) {
        r = q.front().r; c=q.front().c; d = q.front().d;
        q.pop();
        for (int i = 0 ; i < 4; i++) {
            if (i==d) continue;
            nr = r + dr[i]; nc= c +dc[i];
            if (nr >=0 && nc >=0 && nr < mr && nc < mc) {
                if (!maps[nr][nc]) {
                }
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    cin >> mr >> mc;
    pair<int,int>  start;
    vector<pair<int, int> > dest;
    bool find[3];
    for (int i = 0 ; i < mr ; i++) {
        cin >> dt[i];
        for (int j = 0 ; j <mc; j++) {
            if (dt[i][j] == 'S') { start = {i,j};}
            else if (dt[i][j] == 'C') {dest.push_back({i,j});}
            else if (dt[i][j] == '#') {maps[i][j] = INF;}
        }
    }
    return 0;
}