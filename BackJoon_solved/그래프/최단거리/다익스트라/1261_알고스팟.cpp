#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define inf 1000000
using namespace std;

int N, M;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
int visited[100][100];
string dt[100];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N ;
    for (int i = 0; i < N; i++) {cin >> dt[i];
    fill(visited[i], visited[i] + M, inf);}

    priority_queue<pair<int, pair<int, int> > > q;
    q.push({0,{0,0}});
    visited[0][0] = 0;
    
    while(!q.empty()) {
        int cost = -q.top().first;
        int r = q.top().second.first;
        int c = q.top().second.second;
        q.pop();

        for (int i = 0 ; i < 4 ; i++) {
            int nr = r + dr[i]; int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
                if (dt[nr][nc] =='0' && visited[nr][nc] > cost) {
                    visited[nr][nc] = cost;
                    q.push({-cost,{nr,nc}});
                }
                else if (dt[nr][nc] == '1' && visited[nr][nc] > cost+1) {
                    visited[nr][nc] = cost+1;
                    q.push({-(cost+1),{nr,nc}});
                }
            }
        }
    }
    cout << visited[N-1][M-1];

}