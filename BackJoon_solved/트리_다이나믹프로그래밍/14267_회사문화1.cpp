#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> tree[100001];
int dp[100001];

void dfs(int node, int value) {
    int weight = value + dp[node];
    dp[node]+= value;
    for (auto e : tree[node]) {
        dfs(e, weight);
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, Q; cin >> N >> Q;
    int inp;
    for (int i = 1 ; i <= N ; i++) {
        cin >> inp; if (inp == -1) continue;
        tree[inp].push_back(i);
    }
    int a,b;
    for (int i = 0 ; i < Q ; i++) {
        cin >> a >> b;
        dp[a] += b;
    }
    dfs(1,0);
    for (int i = 1 ; i <= N; i++) {
        cout << dp[i] <<' ';
    } return 0;
}