#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
const int inf = 1e4+ 1;
vector<pair<int ,int> > adj[inf];
ll dp[inf];
int sub_node_cnt[inf]; // 자기 자신 포함 루트 0 기준 하위 트리 노드 개수
ll ans = 0; //최종 답

void dfs(int node, int pnode, ll psum = 0) { //루트 0 기준으로 각 노드 마다 sub_tree의 노드 구하기(자기자신포함) 
// 또한 중앙노드를 0으로 기준으로 잡고 총 가중치를 구하기도 위함
    sub_node_cnt[node] = 1; // 전처리 : 해당 노드 개수
    ans += psum; // 이때까지 누적 간선 가중치 더하기

    for (auto &[nxt, cost] : adj[node]) { //자식 노드에 대해서 재호출
        if (nxt == pnode) continue;
        dfs(nxt, node, psum + cost);
        sub_node_cnt[node] += sub_node_cnt[nxt]; //후처리. 해당 node 기준 sub_tree노드 총 수 구하는 과정
    }
}

void solve(int node, int pnode, ll pre_sum, int before_weight) { // node 가 중점으로 둘 경우 중앙트리 가중치 구하기
    ll res = pre_sum - (sub_node_cnt[node])*before_weight + (sub_node_cnt[0]-sub_node_cnt[node])*before_weight;
    // 이전 계산한 값 - (해당 노드의 가중치) * (현재 자신의 sub_tree노드 개수 (부모아님)) + (해당 노드의 가중치) * (0 노드의 sub_tree 노드 수 - 현재 자신의 sub_tree노드 개수 (부모아님))
    ans = min(ans, res);

    // 다음 자식 노드에 대해서 탐색
    for (auto &[nxt, cost] : adj[node]) {
        if (nxt == pnode) continue;
        solve(nxt, node, res, cost);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    int fr, to, cost;
    while (1)
    {
        cin >> n;
        if (n == 0) break;
        for(int i = 0; i <= n; ++i) adj[i].clear();
        memset(dp, 0, sizeof(dp));
        memset(sub_node_cnt, 0, sizeof(sub_node_cnt));
        ans = 0;

        for (int i = 0; i < n-1; ++i) {
            cin >> fr >> to >> cost;
            adj[fr].push_back({to, cost});
            adj[to].push_back({fr, cost});
        }

        dfs(0, -1, 0);
        // cout << ans << '\n';
        // cout << sub_node_cnt[0] << '\n';
        // cout <<"--\n";
        ll tmp = ans;
        // 루트 0 과 연결된 자식들에 대해서 탐색시작
        for (auto &[nxt, cost] : adj[0]) {
            solve(nxt, 0, tmp, cost);
        }
        cout << ans << '\n';
    }
    

    return 0;
}

// 핵심요소!
// 1. 이 문제는 정점이 아닌 간선들의 입장으로 봐야한다. - 일단 Root 0으로 잡고 간선이 사용되는 횟수를 구해야함
//  -> 이 경우는 부모 -> 자식 간선의 호출 횟수 파악해야 하고, 동시에 자식을 루트로 삼는 sub_tree의 모든 노드들의 수와 같음 (자식 노드 포함)

// -->  Root 0으로 기준으로 잡고 각 해당 노드가 sub_root일때 자기자신 포함 sub_tree node개수 구하기

// 2. 중앙 트리 지점을 O(N)으로 옮겨본다고 생각하기
// 만약 기준을 0-> 1로 옮길 경우, 0->1 에 대한 간선만 호출 횟수가 달라짐 (나머지 모든 간선에 대해서의 호출 횟수는 그대로임)
// 따라서 옮겼을 때 해당 계산은 옮겼을 때 호출 횟수만큼으로 바꿔야함
// 즉 해당 노드를 중점으로 잡을 때 총 계산은
// = 이전 계산한 값 - (해당 노드의 가중치) * (현재 자신의 sub_tree노드 개수 (부모아님)) + (해당 노드의 가중치) * (0 노드의 sub_tree 노드 수 - 현재 자신의 sub_tree노드 개수 (부모아님))