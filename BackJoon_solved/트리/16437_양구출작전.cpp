#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int max_n = 123456;

int n;
char t; long long a; int p;

long long cost[max_n+1];
vector<int> adj[max_n+1];

long long dfs(int node) {
    if (adj[node].empty()) return max(cost[node], 0LL); // 말단 노드 -> 양이면 전부 데려가기, 아니면 0

    // 현재 노드
    long long res = cost[node];
    for (int child : adj[node]) {
        res += dfs(child);
    }
    return max(res, 0LL);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        cin >> t >> a >> p;
        cost[i+2] = ( t == 'W' ? -a : a);
        adj[p].push_back(i+2);
    }
    cout << dfs(1);
    return 0;
}

// 말단 노드 -> 양이면 데려가기 아니면 걍 두기
// 그 이외 노드 -> 무조건 일단 거칠 수 밖에 없는 위치
// 일단 자식으로부터 모든 양 혹은 늑대 거친 결과의 합을 보고 양수(양이 많다) -> 가져가기. 음수(늑대) -> 포기