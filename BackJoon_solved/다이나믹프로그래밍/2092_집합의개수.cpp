#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int dv = 1E6;
int dp[201][4001]; //최대값이 i_ row, 집항원소 개수가 A_col일떄 모든 경우의 수
int dt[201];
int T, A, S, B;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> T >> A >> S >> B;
    int temp;
    for (int i = 1 ; i <= A; i++) {cin >> temp; dt[temp]++;}
    dp[0][0] = 1;

    for (int i = 1 ; i <= T ; i++) {
        //단일 숫자로만 구성한 경우
        for (int k = 0 ; k <= dt[i]; k++) {
            ++dp[i][k]; //
        }
        //먼저 i -1 값을 저장
        for (int k = 0; k <= A; k++) {
            dp[i][k] += dp[i-1][k];
            for (int p = 1; p <= dt[i]; p++) {
                if (k - p > 0) dp[i][k] = (dp[i][k] + dp[i-1][k-p])%dv;
            }
        }
    }

    int ans = 0;
    for (int i = S ; i <= B; i++) {
        ans = (ans + dp[T][i])%dv;
    }
    cout << ans;

}