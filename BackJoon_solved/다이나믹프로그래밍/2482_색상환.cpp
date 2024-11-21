#include <iostream>
#include <vector>
#include <algorithm>
#define dv 1000000003
using namespace std;

long long dp[1001][1001];
//N개 색 선택 차례 , i개 인접하지 않은 색 선택 개수
// 현재 색 선택 == 이전 색 선택안됨, 현재 색 선택안됨 == 이전 색 선택됨
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    //기본 경우의 수
    for (int i = 0 ; i <= N ; i++) {
        dp[i][0] = 1; dp[i][1] = i;
    }
    for (int i = 2 ; i <= N; i++) {
        for (int p = 2 ; p <= K; p++) {
            dp[i][p] = dp[i-2][p-1] + dp[i-1][p];
            dp[i][p] %= dv;
        }
     }
    cout << (dp[N-3][K-1] + dp[N-1][K] ) % dv;
    return 0;
}