#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001] = {0,};
int main(void) {
    int N; cin >> N;
    dp[2] = 1; dp[3] = 0; dp[4] = 2; dp[5] = 1;
    for (int i = 6 ; i <= N ; i++) {
        if (dp[i-2] != 0 && dp[i-5] != 0) dp[i] = min(dp[i-2],dp[i-5])+1;
        else if (dp[i-2]!=0) dp[i] = dp[i-2]+1;
        else if (dp[i-5]!=0) dp[i] = dp[i-5]+1;
    }
    cout << (dp[N]== 0 ? -1 : dp[N]);
    return 0;
}