#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX (1<<18)
int table[125][125];
int distan[125][125];

int dr[] = {1,-1,0,0};
int dc[] = {0,0,-1,1};

priority_queue<pair<int, pair<int,int> > > pq; //비용 (음수로), 위치

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, cnt = 0;
    while (true) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> table[i][j];
                distan[i][j] = MAX;
            }
        }
        distan[0][0] = table[0][0];
        pq.push({-table[0][0],make_pair(0,0)});
        int cost, r,c;
        while (!pq.empty()) {
            cost=pq.top().first * (-1); r = pq.top().second.first; c=pq.top().second.second;
            pq.pop();
            if (distan[r][c] < cost) continue;
            for (int i = 0 ; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < N && nc <N) {
                    if (distan[nr][nc] > cost + table[nr][nc]) {
                        distan[nr][nc] = cost + table[nr][nc];
                        pq.push({(-1)*(distan[nr][nc]),make_pair(nr,nc)});
                    }
                }
            }
        }
        cout << "Problem " << ++cnt <<": " << distan[N-1][N-1] <<'\n';
    }
    return 0;
}