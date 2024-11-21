#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int inf = 2e9;
using pii = pair<int, int>;
vector<pii> gh[1001]; //to, cost
int n, m; //노드, 간선 수
int path[1001];
int dist[1001]; 

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> m;
    int a, b, c, cost, node;
    for (int i = 0 ; i < m; ++i) {
        cin >> a >> b >> c; 
        gh[a].push_back({b, c});
        gh[b].push_back({a, c});
    }

    fill(dist, dist + n +1, inf);
    dist[1] = 0;
    priority_queue<pii> pq;
    pq.push({0, 1});

    //첫 다익스트라
    while (!pq.empty())
    {
        cost = -pq.top().first; node =pq.top().second;
        pq.pop();
        for (auto &[nxt, add_cost] : gh[node]) {
            int nxt_cost = cost + add_cost;
            if (dist[nxt] > nxt_cost) {
            path[nxt] = node;
            dist[nxt] = nxt_cost;
            pq.push({-nxt_cost, nxt});
            }
        }
    }
    
    //다음 다익스트란
    int ans = dist[n];
    int idx = n, nxtidx = -1;

    while (idx != 1)
    {
        nxtidx = path[idx];

        pq.push({0, 1});
        fill(dist, dist + n +1, inf);
        dist[1] = 0;

        while (!pq.empty()) {
            cost = -pq.top().first; node =pq.top().second;
            pq.pop();
            for (auto &[nxt, add_cost] : gh[node]) {
                if (idx == node && nxtidx == nxt) continue;
                if (idx == nxt && nxtidx == node) continue;

                int nxt_cost = cost + add_cost;
                if (dist[nxt] > nxt_cost) {
                dist[nxt] = nxt_cost;
                pq.push({-nxt_cost, nxt}); }
            }
        }
        ans = max(ans, dist[n]);
        idx = nxtidx;
    }
    cout << ans;
    return 0;   
}
// 다익스트라 주의 !!
//(dist[nxt] > nxt_cost) . 최단거리, 즉 현재 탐색한 경로가 저장된 길이보다 " 미만 " 인 경우에만 적용하기!!!
// nxt_cost > dist[nxt] -> continue 하지말고
// nxt_cost >= dist[nxt] -> continue 하기