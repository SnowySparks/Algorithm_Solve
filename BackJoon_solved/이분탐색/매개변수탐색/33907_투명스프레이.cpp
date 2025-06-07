#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
const int inf = 1e9 + 7;
const int mv[4][2] = {
    {1, 0},
    {-1, 0},
    {0, -1},
    {0, 1},
};
struct info {
    int r, c, cost;
};
int N, M, K;
int danger[700][700];
int ans = inf;
int dist[700][700];

void clearDist() {
    f(i, 0, N) {
        f(j, 0, M) dist[i][j]=inf;
    }
    dist[0][0] = 0;
}


int isIn(int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= M) return false;
    return true;
}

int simulation(int thresHold) {
    clearDist();
    deque<info> dq;
    dq.push_back({0, 0, 0});

    while (!dq.empty())
    {
        auto [r, c, cost] = dq.front(); dq.pop_front();
        if (cost > dist[r][c]) continue;
        for (auto [dr, dc] : mv) {
            int nr = r + dr, nc = c + dc;
            if (!isIn(nr, nc)) continue;
            int addCost = (danger[nr][nc] > thresHold ? 1 : 0);
            int newCost = addCost + cost;
            if (newCost > K) continue; //최적화 
            if (newCost < dist[nr][nc]) {
                dist[nr][nc] = newCost;
                switch (addCost)
                {
                case 1 :
                    dq.push_back({nr, nc, newCost});
                    break;
                
                case 0 :
                    dq.push_front({nr, nc, newCost});
                    break;
                }
            }
        }
    }
    return dist[N-1][M-1];
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> N >> M >> K;
    int maxDanger = -1, minDanger = 0;
    f(i, 0, N) f(j, 0, M) {
        cin >> danger[i][j];
        maxDanger = max(maxDanger, danger[i][j]);
    }
    while (maxDanger >= minDanger)
    {
        int mid = (maxDanger + minDanger) >> 1;
        int useSpray = simulation(mid);
        if (useSpray <= K) {
            ans = mid;
            maxDanger = mid-1;
        }
        else {
            minDanger = mid + 1;
        }
    }

    cout << (ans == inf ? -1 : ans);
    
    return 0;
}