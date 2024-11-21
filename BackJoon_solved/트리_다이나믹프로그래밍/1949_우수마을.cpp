#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dt[10001];
vector<bool> visited(10001);
int dp[10001][2];
int popu[10001];

void dfs(int root) {
    visited[root] = true;
    dp[root][0] = 0;
    dp[root][1] = popu[root];

    for (auto e : dt[root]) {
        if (visited[e]) continue;
        dfs(e);
        dp[root][0] += max(dp[e][0],dp[e][1]);
        dp[root][1] += dp[e][0];
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i = 1; i <= N ; i++) {
        cin >> popu[i];
    }
    int a,b;
    //무방향 그래프 
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        dt[a].push_back(b);
        dt[b].push_back(a);
    }
    dfs(1);
    cout << max(dp[1][0] , dp[1][1]); return 0;
}   