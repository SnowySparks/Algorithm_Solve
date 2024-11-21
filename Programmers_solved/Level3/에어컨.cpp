#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define f(a,b,c) for (int a= b; a<=c;a++)
int dp[1001][52];
const int inf = 1e8+1;
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    temperature += 11; t1+=11; t2+=11;
    int time = onboard.size()-1;
    f(i,0,time) f(k,0,51) dp[i][k] = inf;
    dp[0][temperature] = 0;
    int start, end;
    f(i,1,time) {
        if (onboard[i]) {
            start = t1; end = t2;
        }
        else {
            start = min(t1,temperature); end =max(t2,temperature);
        }

        f(k,start,end) {
            dp[i][k] = min(dp[i][k] , dp[i-1][k] + (k == temperature ? 0 : b));
            if (k > temperature) dp[i][k] = min(dp[i][k],min(dp[i-1][k-1] + a, min(dp[i-1][k+1],dp[i-1][k]+b) ));
            if (k < temperature) dp[i][k] = min(dp[i][k],min(dp[i-1][k-1],min(dp[i-1][k+1]+a,dp[i-1][k]+b)));
        }
    }
    int answer = *min_element(dp[time]+start,dp[time]+end+1);
    return answer;
}