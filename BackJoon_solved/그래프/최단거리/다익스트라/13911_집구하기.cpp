#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;
const int INF = 1e9 + 7;
const int max_V = 1e5;
int V, E, M, S; // 노드 개수, 간선 개수, 맥도날드 개수, 스벅 개수
int x, y; // 맥도날드 최대거리, 스벅 최대 거리
vector<int> macdonals, starbucks; // 맥도날드, 스벅 노드 위치
int m_dist[max_V + 1]; // 맥도날드 - 다익스트라
int s_dist[max_V + 1]; // 스타벅스 - 다익스트라
bool isNotHome[max_V + 1]; // 여기는 집이 아닌 노드인가?

vector<pair<int, int> > adj[max_V+1]; // 거리, 다음 노드 위치

void dijkstra(const vector<int> &start_nodes, int *dist) {
    priority_queue<pair<int ,int>> pq; // -거리, 노드위치   
    for (int i = 1; i <= V; ++i) dist[i] = INF;
    for (int node : start_nodes) {
        dist[node] = 0;
        pq.push({0, node});
    }
    int cur_dist, cur_node;
    while (!pq.empty())
    {
        tie(cur_dist, cur_node) = pq.top();
        pq.pop();
        cur_dist= -cur_dist;

        for (auto [cost, nextNode] : adj[cur_node]) {
            int new_cost = cost + cur_dist;
            if (new_cost < dist[nextNode]) {
                dist[nextNode] = new_cost;
                pq.push({-new_cost, nextNode});
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    // 입력 ----------------
    cin >> V >> E;
    int temp;
    int u, v, w; // node1, node2, 거리 입력 
    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    // 맥도 날드
    cin >> M >> x;
    while (M--)
    {
        cin >> temp;
        isNotHome[temp] = true;
        macdonals.push_back(temp);
    }


    // 스벅
    cin >> S >> y;
    while (S--)
    {
        cin >> temp;
        isNotHome[temp] = true;
        starbucks.push_back(temp);
    }

    // 시물레이션 --------------------------
    dijkstra(macdonals, m_dist);
    dijkstra(starbucks, s_dist);
    // dist_out();

    int ans = INF;
    for (int i = 1; i <= V; ++i) {
        if (isNotHome[i]) continue; // 여긴 맥도날드 혹은 스벅임
        if (m_dist[i] > x || s_dist[i] > y) continue; // 맥도날드, 스벅 최대 거리 벗어남

        ans = min(ans, m_dist[i] + s_dist[i]);
    }
    cout << (ans == INF ? -1 : ans);
    return 0;
}

// 플이
// 먼저 Naive하게 생각해 보면 다음과 같음 : 각 집에서 다익스트라 돌려서 스벅, 맥도날드 거리 다 측정하고 비교 -> 이걸 여러번
// 하지만 생각해보면 다익스트라의 시간복잡도는 ElogV로 볼 수 있는데 이걸 모든 집마다 돌리면 분명히 시간 초과가 남
// 역발상 생각을 하여 오히려, 각 맥도날드, 스타벅스 지점 위치에서 집으로 역으로 다익스트라 계산 하는 방법이 있음
// 해당 그래프는 "양방향 그래프" 이기에 A->B의 거리는 B->A 거리와 완전히 동일함
// 직접 해당 위치에 거리 0으로 지정하는 방법도 있고, 별도의 노드를 추가하여 해당 노드 - (스벅 혹은 맥도날드) 연결하는 방법 이 있음 (가중치 0)
// 이렇게 하면 다익스트라 단 2회만으로 모든 집 각각 마다 스벅, 맥도날드의 최소 거리를 구할 수 있음