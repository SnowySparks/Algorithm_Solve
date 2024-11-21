#include <string>
#include <vector>
#include <algorithm>
#define inf (int)1<<28
using namespace std;
vector<int> gh[100001];
int dp[100001][2];
bool visited[100001];

//트리 + 다이나믹프로그래밍으로 극단적으로 시간단축

void dfs(int root) {
    visited[root] = true;
    dp[root][0] = 0;
    dp[root][1] = 1;

    for (auto e : gh[root]) {
        if (visited[e]) continue;
        dfs(e);
        dp[root][0]+=dp[e][1];
        dp[root][1]+=min(dp[e][1], dp[e][0]);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    for (auto e : lighthouse) {
        gh[e[0]].push_back(e[1]);
        gh[e[1]].push_back(e[0]);
    }
    for (int i = 1 ; i <= n ; i++) {
        visited[i] = false;
    }
    dfs(1);

    return min(dp[1][0], dp[1][1]);
}