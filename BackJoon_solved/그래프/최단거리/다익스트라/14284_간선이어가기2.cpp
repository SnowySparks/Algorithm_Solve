#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 7E6;
int n,m,s,t;
vector<pair<int,int> > gh[5001];
int dist[5001];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int a, b, c;
    while(m--) {
        cin >> a >> b >> c;
        gh[a].push_back({b,c});
        gh[b].push_back({a,c});
    }
    cin >> s >> t;
    fill(dist, dist+n+1, inf);
    dist[s] = 0;
    priority_queue<pair<int,int> > pq;
    pq.push({0,s});
    while(!pq.empty()) {
        int cost = -pq.top().first, loc = pq.top().second; pq.pop();
        if (dist[loc] < cost) continue;
        for (auto e : gh[loc]) {
            if (dist[e.first] > e.second + cost) {
                dist[e.first] = e.second + cost;
                pq.push({-(e.second+cost),e.first});
            }
        }
    }
    cout << dist[t];
    return 0;
}