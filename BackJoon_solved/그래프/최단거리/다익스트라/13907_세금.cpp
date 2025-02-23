#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int ,int>;
vector<pii> adj[1010];
int n, m, k, s, d;
int dist[1010][1010];
int tax[30010];
const int inf = 2e9;
struct info {
    int loc, cnt; int cost;
    bool operator>(const info &o) {
        return cnt > o.cnt;
    }
    info(int loc, int cnt, int cost) : loc(loc), cnt(cnt), cost(cost) {};
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    cin >> s >> d;
    int a, b; int w;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    for (int i = 1; i <= k; ++i) {
        cin >> tax[i];
        tax[i] += tax[i-1];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) dist[i][j] = inf;
    }
    
    dist[s][0] = 0;
    priority_queue<info, vector<info>, greater<> >pq;
    pq.push(info(s, 0, 0));
    while (!pq.empty())
    {
        int loc = pq.top().loc;
        int cnt = pq.top().cnt;
        int cost = pq.top().cost;
        pq.pop();
        if (dist[loc][cnt] < cost) continue;
        if (loc == d) continue; //이미 도착한 것에 대해서 더 다룰 필요 없음
        for (auto &[w, nxt] : adj[loc]) {
            int newCost = w + cost;
            if (dist[nxt][cnt+1] > newCost) {
                dist[nxt][cnt+1] = newCost;
                pq.push(info(nxt, cnt+1, newCost));
            }
        }
    }

    // 실제 도달 가능성 있는 것만 추출
    vector<pii> ansLst;
    for (int i = 1; i <= n; ++i) {
        if (dist[d][i] < inf) ansLst.push_back({i, dist[d][i]});
    }
    for (int i = 0; i <= k; ++i) {
        int ans = inf;
        for (auto &[cnt, cost] : ansLst) {
            ans = min(ans, cnt*tax[i] + cost);
        }
        cout << ans << '\n';
    }

    return 0;
}