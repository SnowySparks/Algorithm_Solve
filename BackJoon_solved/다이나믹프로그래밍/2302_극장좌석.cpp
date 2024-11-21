#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[41];
bool vip[41];
int main(void) {
    int N, M;
    cin >> N >> M;
    int idx = 1; int inp;
    long long answer = 1;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4 ; i <= 40; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }

    while(M--) {
        cin >> inp;
        answer *= dp[inp - idx];
        idx = inp+1;
    }
    answer *= dp[N - inp];

    cout << answer; return 0;
}