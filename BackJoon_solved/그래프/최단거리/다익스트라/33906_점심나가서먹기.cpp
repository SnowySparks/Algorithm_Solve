#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int ,int> pii;
const int N = 1e5, M = 2e5;
const int inf = 2e9 + 1;
int restaurant[N+1], cafe[N+1]; //레스토랑, 카페
int n, m; //건물수, 

vector<pii> adj[N+1]; //<다음 건물, 비용>
bool visited[N+1];
int distAtRest[N+1];
int distAtCafe[N+1];

int minVisitedRestaurant = 0, minVisitedCafe = 0;


void canVisit() {
    visited[1] = true;
    queue<int> q; q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto &edge : adj[cur]) {
            int nxt = edge.first;
            if (visited[nxt]) continue;
            visited[nxt] = true;
            q.push(nxt);
        }
    }
}  

void findMinLocation() {
    int resCost = inf, cafeCost = inf;
    for (int i = 1; i <= n; ++i) {
        if (restaurant[i] > 0 && visited[i]==true &&resCost > restaurant[i]) {
            resCost = restaurant[i];
            minVisitedRestaurant = i;
        }
        if (cafe[i] > 0 && visited[i]==true && cafeCost > cafe[i]) {
            cafeCost = cafe[i];
            minVisitedCafe = i;
        }
    }
}

void dijk(int dist[], int loc) {
    for (int i = 1; i <= n; ++i) dist[i] = inf;
    dist[loc] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, loc});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int nowLoc = pq.top().second;
        pq.pop();

        if (cost > dist[nowLoc]) continue;
        
        for (auto [nxt, addCost] : adj[nowLoc]) {
            int newCost = cost + addCost;
            if (dist[nxt] > newCost) {
                dist[nxt] = newCost;
                pq.push({newCost, nxt});
            }
        }
    }
    
}

long long calDist() {
    return (1LL * distAtCafe[1]) + (1LL * distAtRest[1]) + (1LL * distAtCafe[minVisitedRestaurant]);
}
 

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> restaurant[i];
    for (int i = 1; i <= n; ++i) cin >> cafe[i];

    int u, v, w;

    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    canVisit();
    findMinLocation();
    dijk(distAtRest, minVisitedRestaurant);
    dijk(distAtCafe, minVisitedCafe);

    cout << calDist();


    return 0;
}