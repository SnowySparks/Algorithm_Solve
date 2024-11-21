// https://www.codetree.ai/missions/9/problems/touring-the-line/description
#include <iostream>
#include <vector>
#include <cstring>
#define pii pair<int ,int>
#define pil pair<int, long long>
#define f(a,b,c) for (int a =b; a<c;++a)
using ll = long long;
using namespace std;
const int max_n = 5e4+1;
vector<pil> adj[max_n];
int n; ll d; 
int tmp_node; ll dist = 0; int edge_cnt_max = 0;
int edge_cnt1[max_n];
int edge_cnt2[max_n];
ll cost1[max_n];
ll cost2[max_n];
void dfs1(int node, int pnode, int val, int *edge_cnt = edge_cnt1) {
    edge_cnt[node] = val;
    if (edge_cnt_max < val) {
        edge_cnt_max = val;
        tmp_node = node;
    }

    for (auto &[nxt, dist] : adj[node]) {
        if (nxt == pnode) continue;
        dfs1(nxt, node, val+1);
    }
}

void dfs2(int node, int pnode, ll val, ll *cost) {
    cost[node] = val;
    for (auto &[nxt, dist] : adj[node]) {
        if (nxt == pnode) continue;
        dfs2(nxt, node, val+dist, cost);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    ll ans = 1e18;
    // input
    cin >> n >> d;
    int fr, to; ll dst;
    f(i, 0, n-1) {
        cin >> fr >> to >> dst;
        adj[fr].push_back({to, dst});
        adj[to].push_back({fr, dst});
    }

    // 모든 간선 길이 1로 취급 - 
    // 즉 모든 간선 가중치를 1로 둔 트리의 반지름 구하기 (간선 가장 많이 거치는 경우)
    // 단. 간선은 거치는 경우가 가장 많은 경우도 무시 못함
    dfs1(1, -1, 0);
    memset(edge_cnt1, 0, sizeof(edge_cnt1));
    int node_1 = tmp_node;
    dfs1(tmp_node, -1, 0);
    int node_2 = tmp_node;
    int max_edge = edge_cnt_max;
    // 가중치 1 기준 트림 지름(최대 간선 수) 및 그 노드 위치
    memset(edge_cnt1, 0, sizeof(edge_cnt1));
    // 해당 지름노드에서 다시 가중치 1기준으로 재탐색 - 트리 지름 후보는 여러개 가능성
    dfs1(node_1, -1, 0, edge_cnt1);
    dfs1(node_2, -1, 0, edge_cnt2);
    // -----

    // 가중치 1 기준의 트리 지름의 시작점 기준으로 거리탐색
    dfs2(node_1, -1, 0, cost1);
    dfs2(node_2, -1, 0, cost2);

    f(i, 1, n+1) cout << edge_cnt1[i] << ' ';
    cout << "\n---\n";
    f(i, 1, n+1) cout << edge_cnt2[i] << ' ';
    cout << '\n';

    // 트리 반지름 될 수 있는 모든 노드들 중 가장 최단시간이 답
    for (int i = 1; i <= n; ++i) {
        if (cost1[i] && edge_cnt1[i] == max_edge) ans = min(ans, (cost1[i]/d + (cost1[i]%d != 0 ? 1 : 0)));
        if (cost2[i] && edge_cnt2[i] == max_edge) ans = min(ans, (cost2[i]/d + (cost2[i]%d != 0 ? 1 : 0)));
    }
    cout << ans;

    return 0;
}