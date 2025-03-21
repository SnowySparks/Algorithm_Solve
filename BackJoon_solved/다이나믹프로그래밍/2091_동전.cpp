#include <iostream>
#include <cstring>
using namespace std;
int dp[10001][5]; // i원을 내기 위해서 최대 동전 수 일때, j번째 코인의 개수, 단 4번째는 모든 코인의 수
int x, coins[4];
int price[4] = {1, 5, 10, 25};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> x;
    for (int i = 0; i < 4; ++i) cin >> coins[i];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 5; ++i) dp[0][i] = 0;

    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < 4; ++j) {
            // 금액의 범위가 음수가 될 수 없음
            if (i - price[j] < 0) continue;

            // 코인 추가가 가능한 경우
            if (dp[i-price[j]][j] + 1 <= coins[j]) {

                // -1 : 불가능한 것 -> 스킵!
                if (dp[i-price[j]][j] == -1) continue; 

                // 최대 개수 갱신 가능할 때만 답 갱신
                if (dp[i-price[j]][4] + 1 > dp[i][4]) {
                    for (int k = 0; k <= 4; ++k) dp[i][k] = dp[i-price[j]][k];
                    dp[i][j]++;
                    dp[i][4]++;
                }
            }
        }
    }
    //  -1 는 0으로 출력하기 조치
    for (int i = 0; i < 4; ++i) cout << (dp[x][i] <= 0 ? 0 : dp[x][i]) << ' ';

    return 0;
}