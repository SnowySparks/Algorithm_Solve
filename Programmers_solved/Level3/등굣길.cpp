#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[101][101];
    dp[1][1]=1;
    int a,b;

    for (auto e : puddles) {
        dp[e[0]][e[1]] = -1;
    }

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            a=0;b=0;
            if (dp[i][j] == -1) continue;
            if (dp[i-1][j] != -1) a= dp[i-1][j];
            if (dp[i][j-1] != -1) b= dp[i][j-1];
            dp[i][j] = (a+b)%1000000007;
        }
    }
    return dp[n][m];
}