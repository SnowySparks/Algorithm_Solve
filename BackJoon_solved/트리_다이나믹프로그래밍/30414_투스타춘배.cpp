#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N = 1e5;
const int INF = 1e9 + 7;

int N, P; // 노드 수 , 시작 위치
vector<int> tree[MAX_N+1];
int originHeight[MAX_N+1]; // 원래 높이
int wantHeight[MAX_N+1]; // 원하는 높이
int dp[MAX_N+1]; // P 위치 기준 그 하위 노드까지 포함 필요한 최소 비용

void dfs(int pnode, int node) {
    for (int child : tree[node]) {
        if (child == pnode) continue; // 부모 노드이면 스킵
        dfs(node, child);
        dp[node] += max(dp[child], 0);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> P;
    int a, b;
    for (int i = 1; i <= N; ++i) cin >> originHeight[i];
    for (int i = 1; i <= N; ++i) cin >> wantHeight[i];
    for (int i = 1; i <= N; ++i) dp[i] = wantHeight[i] - originHeight[i];
    for (int i = 0; i < N-1; ++i) {
        cin >> a >> b;
        // 양방향 트리 입력
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(-1, P);
    cout << max(dp[P], 0);
    return 0;
}

// 원리
// 이 문젠 tree 구조에 한번 방문하면 더이상 방문이 불가능함 -> 루트 노드 기준 자식으로 무ㅜ조건 이동
// 자식들 중 비용이 드는 쪽은 처리해야 하난 안드는 쪽은 0으로 처리
