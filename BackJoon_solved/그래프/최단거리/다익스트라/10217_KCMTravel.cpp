#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define f(a,b,c) for (int a=b; a<c; a++)
using piii = pair<int, pair<int, int> >;
const int inf = 1e8;
int n, m, k;

int info[101][10001]; // i 위치에 최대 K 비용으로 갈수있는 최소 시간

vector<vector<piii> > gh;

void dijkstra(int start_node) {
    info[start_node][0] = 0;
    priority_queue <piii, vector<piii>, greater<piii> > pq;
    pq.push({0,{1,0}});

    while(!pq.empty()) {
        int loc = pq.top().second.first, _cost = pq.top().second.second, time = pq.top().first;
        pq.pop();

        if (info[loc][_cost] < time) continue;

        for(piii val : gh[loc]) {
            int next = val.second.first;
            int ncost = _cost + val.second.second;
            int ntime = time + val.first;
            
            if (ncost <= m && ntime < info[next][ncost]) {
                f(j,ncost,m+1) {
                    if (info[next][j] <= ntime) break;
                    info[next][j] = ntime;
                }
                pq.push({ntime,{next,ncost}});
            }

        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    f(t,1,tc+1) {
        cin >> n >> m >> k;
        gh.clear();
        gh.resize(n+1);
        f(i,0,n+1) {
            f(j, 0 ,m + 1) info[i][j] = inf;
        }

        f(i,0,k) {
            int u, v, c, d; cin >> u >> v >> c >> d;
            gh[u].push_back({d,{v,c}});
        }
        f(i,1,n+1) sort(gh[i].begin(),gh[i].end());
        dijkstra(1);

        int ans = inf;
        f(i,0,m+1) ans = min(ans, info[n][i]);
        
        if (ans >= inf) cout << "Poor KCM" <<'\n';
        else cout << ans << '\n';
    }
    return 0;
}