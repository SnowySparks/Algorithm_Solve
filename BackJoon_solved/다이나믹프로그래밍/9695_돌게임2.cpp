#include <iostream>
#include <vector>
using namespace std;


bool dp[1001]; //남는 돌이 idx개일 때 누가 이기나, false = SK win, true = CY win
//상근이가 가장 먼저 돌을 져감
//다음 상근이 턴은 2개, or 4개, 6개 돌이 사라져있는 상태
int main(void) {
    int N; cin >> N;
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = false;
    dp[5] = true;

    for (int i = 6 ; i <= N ; i++) {
        if (dp[i-1] || dp[i-3]) dp[i] = false;
        else dp[i] = true;
    }
    cout << (dp[N] ? "CY" : "SK");
    return 0;
}