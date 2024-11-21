#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define f(a, b, c) for(int a=b;a<c;++a)
using pii = pair<int ,int>;
const int MAXN = 1e3+1;
const int INF = 1e9+7;
vector<pii> adj[MAXN]; // {nxt, cost}
int dist[MAXN];
int n, m, k;
priority_queue<pair<int ,int> > pq;

priority_queue<int> weight[MAXN]; // 각 노드마다할당. 1에서부터 


void dijkstra() {
    f(i, 0, n+1) dist[i] = INF;
    weight[1].push(0);

    int acc_cost, node;
    pq.push({0, 1}); // {누적비용, 노드}
    while (!pq.empty())
    {
        tie(acc_cost, node) = pq.top(); pq.pop();
        acc_cost=-acc_cost;
        for (auto &[nxt, cost] : adj[node]) {
            int nxt_cost = acc_cost + cost;

            if (weight[nxt].size() < k) {
                weight[nxt].push(nxt_cost);
                pq.push({-nxt_cost, nxt});
            }
            else if (weight[nxt].top() > nxt_cost) {
                weight[nxt].pop();
                weight[nxt].push(nxt_cost);
                pq.push({-nxt_cost, nxt});
            }
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    int a, b ,c;
    f(i, 0, m) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dijkstra();
    f(i, 1, n+1) {
        if (weight[i].size() == k) cout << weight[i].top() << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}

// 다익스트라 번형 버전
// 기존 다익스트라 방식은 각 노드마다 "최소" 값만 저장하면 되었으나. 이번에는 최소 k개 남겨야 한다는 것이 큰 포인트
// 각 노드마다 1부터 도달 가능한 최소 거리값 목록을 저장함 (최대 k개만)
// 해당 노드마다 우선순위큐는 내림차순(큰게 우산적) -> 제거 우선순위의미로써 (쉽게 제거하기 위해)
// 기존의 다익스트라는 받아온 거리가 저장된 거리보다 크면 뒤로 보내지 않지만, 이 문제에서는 모두 통과시켜주어야 한다