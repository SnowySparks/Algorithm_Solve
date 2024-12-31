#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define NOT_MENTO 0
#define MENTO 1
const int MAX_N = 2e5 + 1;

ll dp[MAX_N][2]; // 루트 노드가 I인 서브트리, 자기자신이 멘토인 경우/아닌경우
int weight[MAX_N], n;
int state[MAX_N]; // 노드 i 가 어떤 상태인지
vector<int> adj[MAX_N];

void dfs(int node) {
    if (adj[node].empty()) return;
    
    ll max_value = 0;

    // 자기 자신이 멘토가 아닐떄 (멘티이거나, 아무 무직이거나)
    for (int child : adj[node]) {
        dfs(child);
        dp[node][0] += max(dp[child][0], dp[child][1]);
        max_value = max(dp[child][0], ( dp[child][0] - max(dp[child][1],dp[child][0]) + weight[child]*weight[node] ));
    }
    // 자기자신이 멘토일 떄
    ll total = dp[node][0];

    // 일단 각 자식들의 상태를 보기 - dp값이 큰 쪽이 어떤 상태인가
    for(int child : adj[node]) {
        state[child] = (dp[child][MENTO] > dp[child][NOT_MENTO] ? MENTO : NOT_MENTO);
    }
    for(int child : adj[node]) {
        // 해당 자식을 무조건 멘티로 만들어서 쌍을 만든다고 가정
        ll tmp = dp[node][0] - dp[child][state[child]]; 
        tmp += dp[child][0] + weight[node]*weight[child];
        dp[node][1] = max(dp[node][1], tmp);
    }

}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    int tmp;
    for (int i = 2; i <= n; ++i) {
        cin >> tmp; // 사수 입력
        adj[tmp].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> weight[i];
    dfs(1);
    // for (int i = 1; i <= n; ++i) {
    //     cout << i<<':' << dp[i][0] << ' ' << dp[i][1] <<'\n';
    // }
    cout << max(dp[1][1], dp[1][0]);
    return 0;
}

// 원리
// dp[i][j] 해당 노드 i가 서브 루트 이면서, j = (멘토, 멘토가 아니다)
// j = 0 인 경우, 자식들의 경우들은 다 독립시행
// J = 1 인 경우, 자식들 중 하나만 멘티-멘토 영향주고 나머지는 독립시행이 된다.
// 이 때 해당 자식끼리만 멘토-멘티 관계 와 나머지 자식들의 Dp값의 총합들 중 가장 큰 값을 갱신