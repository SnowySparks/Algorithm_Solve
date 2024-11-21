#include <string>
#include <vector>
#include <cstring>
using namespace std;
#define div 1000000007
// dp[n][count]
int solution(int n, int count) {
    int answer = 0;
    long long dp[101][101];
    memset(dp,0,sizeof(dp));
    dp[1][1] = 1;
    long long temp;

    for (int i = 2 ; i <= n ; i++) {
        for (int j = 1 ; j <= i; j++) {
            if (j == 1) temp = dp[i-1][j] * 2*(i-1);
            else if (j == i) temp = dp[i-1][j-1];
            else temp = (dp[i-1][j-1] + dp[i-1][j]*(2*(i-1)));
            dp[i][j] = temp % div;
        }
    }
    return (int) (dp[n][count] % div);
}