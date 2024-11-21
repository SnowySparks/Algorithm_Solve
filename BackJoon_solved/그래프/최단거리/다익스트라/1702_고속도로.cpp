#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define f(a,b,c) for (int a=b; a<c; a++)
const int inf = 1E8;
int N, M,start, ed;


typedef struct _io {
    int loc, cost, time; //
    bool operator>(const struct _io &p) const {
        if (time == p.time) return cost > p.cost;
        return time > p.time;
    }
    bool operator<(const struct _io &p) const {
        if (time == p.time) return cost < p.cost;
        return time < p.time;
    }
} io;

vector<io> gh[101];
int tb[101][10001]; // row : node , column : cost , value : lowest time;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> start >> ed;
    int max_cost = 0;
    int p, r, c, t;
    f(i,0,M) {
        cin >> p >> r >> c >> t;
        gh[p].push_back({r,c,t});
        gh[r].push_back({p,c,t});
        max_cost = max(max_cost, N*c);
    }
    priority_queue<io, vector<io>, greater<> > pq;

    f(i,0,101) f(k, 0, 10001) tb[i][k] = inf;
    tb[start][0] = 0;
    pq.push({start,0,0});
    while(!pq.empty()) {
        int loc = pq.top().loc, time = pq.top().time, cost = pq.top().cost; pq.pop();
        if ( tb[loc][cost] < time) continue;
        for (io e : gh[loc]) {
            if (cost + e.cost <= max_cost && tb[e.loc][e.cost + cost] > time + e.time) {
                tb[e.loc][e.cost + cost] = time + e.time;
                f(t,cost+e.cost , max_cost+1) tb[e.loc][t] = min(tb[e.loc][t],time+e.time);
                pq.push({e.loc, e.cost + cost, e.time + time});
            }
        }
    }
    int ans = 0;
    int min_dist = inf;
    f(i,0,max_cost+1) {
        if (tb[ed][i] != inf && tb[ed][i] < min_dist) {
            min_dist = tb[ed][i];
            ans++;
        }
    }
    cout << ans; return 0;
}