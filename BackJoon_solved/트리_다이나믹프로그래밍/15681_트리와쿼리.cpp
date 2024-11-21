#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001];
bool visited[100001];
vector<int> gh[100001];

void dfs(int root) {
    if (dp[root]!=0) return;
    visited[root] = true;
    int cnt = 1;
    for (int i = 0 ; i < gh[root].size(); i++) {
        int next = gh[root][i];
        if (visited[next]) continue;
        dfs(next);
        cnt+=dp[gh[root][i]];
    }
    dp[root] = cnt;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, R, Q; cin >> N >> R >> Q;
    int U, V;
    for (int i = 0 ; i < N-1 ; i++) {
        cin >> U >> V;
        gh[U].push_back(V);
        gh[V].push_back(U);
    }
    dfs(R);
    int inp;
    while (Q--) {
        cin >> inp;
        cout << dp[inp] <<'\n';
    }
    return 0;
}