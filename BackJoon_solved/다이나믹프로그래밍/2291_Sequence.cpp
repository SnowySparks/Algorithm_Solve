#include <iostream>
#include <vector>
using namespace std;

int n, m, k; // 자연수분할개수, 총합, 몇 번째 
int dp[222][222]; // 자연수 (i) 를 j개의 자연수로 분할하는 방법의 수

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;

    dp[0][0] = 1;
    for (int num = 1; num <= m; ++num) {
        for (int groupCnt = 1; groupCnt <= min(10, num); ++groupCnt) {
            if (num-groupCnt < 0) continue;
            dp[num][groupCnt] = dp[num-1][groupCnt-1] + dp[num-groupCnt][groupCnt];
        }
    }

    int num = 1; // 오름차순 출력
    while (n > 0 && m > 0)
    {
        n--; m--;

        while (k > dp[m][n]) {
            k -= dp[m][n];
            m -= n + 1;
            ++num;
        }
        cout << num << ' ';
    }
    

    return 0;
}