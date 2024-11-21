#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dt[100001];
int dp[100001][2];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i = 1 ; i <= N ; i++) cin >> dt[i];
    int answer = 1;
    dp[1][0] = 1; dp[1][1] = 1; 
    for (int i = 2 ; i <= N ; i++) {
        if (dt[i-1] <= dt[i]) dp[i][0] = dp[i-1][0]+1;
        else dp[i][0] = 1;

        if (dt[i-1] >= dt[i]) dp[i][1] = dp[i-1][1] + 1;
        else dp[i][1] = 1;

        answer = max(answer, max(dp[i][0], dp[i][1]));
    }
    cout << answer;
    return 0;
}