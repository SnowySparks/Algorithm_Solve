#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define inf 2000000000
using namespace std;

vector<pair<int ,int> > dt[50001];
int dist[50001];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for (int i = 0 ; i <= N ; i++) {dist[i] = inf;}
    int st,en,c;
    for (int i = 0 ; i < M ; i++) {
        cin >> st >> en >> c;
        dt[st].push_back({c,en});
        dt[en].push_back({c,st});
    }
    priority_queue<pair<int, int> > pq; //비용 , 노드
    pq.push({0,1}); dist[1] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (dist[node] < cost) continue;
        for (auto e : dt[node] ) {
            int next_cost = cost + e.first;
            if (dist[e.second] > next_cost) {
                dist[e.second] = next_cost;
                pq.push({-next_cost,e.second});
            }
        }
    }
    cout << dist[N];
    return 0;
}