#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
#define SAFE '.'
#define SLIP 'S'
#define DANGER '#'
const int inf = 1e9;

const int mv[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};
int n;
char ch[50][51];
int dist[50][50][6];
bool isIn(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n) return false;
    return true;
}
bool canPass(int r, int c, int dir, int k) {
    if (!isIn(r + k*mv[dir][0], c + k*mv[dir][1])) return false;
    if (ch[r + k*mv[dir][0]][c + k*mv[dir][1]] == SLIP) return false;
    f(i, 1, k+1) {
        if (ch[r + i*mv[dir][0]][c + i*mv[dir][1]] == DANGER) return false; 
    }
    return true;
}
void init() {
    f(i, 0, n) f(j, 0, n) f(t, 0, 6) dist[i][j][t] = inf;
}

struct info {
    int r, c, k, cost;
    bool operator<(const info &other) const {
        return cost < other.cost;
    }
    bool operator>(const info &other) const {
        return cost > other.cost;
    }
};

int costJumpChange(int before, int after) {
    int res = 0;
    if (before == after) return res;
    else if (before < after) {
        f(i, before+1, after+1) res+= i*i;
    }
    else {
        res = 1;
    }
    return res;
}

int dijkstra(int sr,int sc, int er, int ec) {
    init();
    dist[sr][sc][1] = 0;
    priority_queue<info, vector<info>, greater<info> > pq;
    pq.push({sr, sc, 1, 0});

    while (!pq.empty())
    {
        int r = pq.top().r;
        int c = pq.top().c;
        int k = pq.top().k;
        int cost = pq.top().cost;
        pq.pop();
        // cout << r << ' ' << c << ' ' << k << ' ' << cost << '\n';
        if (dist[r][c][k] < cost) continue;

        f(dir, 0, 4) {
            f(newK, 1, 6) {
                int jumpCost = costJumpChange(k, newK);
                if (!canPass(r, c, dir, newK)) continue;
                int nr = r + newK * mv[dir][0];
                int nc = c + newK * mv[dir][1];
                int calCost = cost + jumpCost + 1;
                if (dist[nr][nc][newK] > calCost) {
                    dist[nr][nc][newK] = calCost;
                    pq.push({nr, nc, newK, calCost});
                }

            }
        }
    }
    int minCost = *min_element(dist[er][ec]+1, dist[er][ec] + 6);
    if (minCost >= inf) return -1;
    return minCost;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    f(i, 0, n) cin >> ch[i];
    int q; cin >> q;
    int r1, c1, r2, c2;
    f(query, 0, q) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << dijkstra(r1-1, c1-1, r2-1, c2-1) << '\n';
    }
    return 0;
}