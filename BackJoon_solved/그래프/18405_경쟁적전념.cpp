#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dt[200][200];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<pair<int, pair<int ,int> > > V; //바이러스 , (위치)
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dt[i][j];
            if (dt[i][j] != 0) {
                V.push_back({dt[i][j],{i,j}});
            }
        }
    }
    int S, fR, fC; cin >> S >>fR >> fC;
    int nowS= 0;
    int cnt = 0;
    sort(V.begin(), V.end());
    queue<pair<int, pair<int, int> > > q;
    for (auto e : V) {q.push(e);} 
    cnt = q.size();

    while(!q.empty()) {
        int virus = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        for (int i = 0; i < 4 ; i++) {
            int nr = r + dr[i]; int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
                if (dt[nr][nc] == 0) {
                    dt[nr][nc] = virus;
                    q.push({virus,{nr,nc}});
                }
            }
        }
        cnt--;
        if (cnt == 0 ) {nowS++; cnt= q.size();}
        if (nowS == S) break;
    }
    cout << dt[fR-1][fC-1] ;
    return 0;
}