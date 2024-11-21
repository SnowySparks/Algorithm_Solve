#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using ll = long long;
#define f(a,b,c) for(int a = b; a < c; a++)
using namespace std;
const long long inf = 1E12;
const int to = 1E4+1;
ll dp[to][21];

vector<pair<int,int> > gh[to];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N , M, K; cin >> N >> M >> K;
    f(i,0,M) {
        int f, t, c; cin >> f >> t >> c;
        gh[f].push_back({t,c});
        gh[t].push_back({f,c});
    }
    f(i,0,N+1) fill(dp[i],dp[i]+K+1,inf);
    priority_queue<pair<ll, pair<int,int> > > pq; // 비용 , 노드 , 도로공사횟수
    pq.push({0,{1,0}});
    dp[1][0] = 0;
    while(!pq.empty()) {
        ll cost = -pq.top().first;
        int node = pq.top().second.first;
        int done = pq.top().second.second;
        pq.pop();

        if (dp[node][done] < cost) continue;

        for( auto e : gh[node]) {
            ll next_nok = cost + e.second;
            if (dp[e.first][done] > next_nok) {
                dp[e.first][done] = next_nok;
                pq.push({-next_nok,{e.first,done}});
            }
            if (done < K && cost < dp[e.first][done+1]) {
                dp[e.first][done+1] = cost;
                pq.push({-cost,{e.first,done+1}});
            }
        }
    }
    ll ans = inf;
    f(i,0,K+1) ans = min(ans, dp[N][i]);
    cout << ans; return 0;
}