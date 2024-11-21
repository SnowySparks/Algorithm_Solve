#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;

int dp[71][1<<7];
int arr[71];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 7 ; i < 7*(n+1); i++) cin >> arr[i];

    for (int day = 7 ; day < 7*(n+1); day++) { //현재 대상 날짜
        for ( int i = 0 ; i < (1<<7); i++) { // 이전 날짜 데이터
            int nxt = (i<<1) & ((1<<7) - 1); //현재 적용 대상
            if (day%7 == 0) { //월요일
                if ( !(i & (1<<6))) {
                    dp[day][nxt|1] = max(dp[day][nxt|1], dp[day-1][i] + arr[day]);
                }
                else dp[day][nxt] = max(dp[day][nxt], dp[day-1][i]);
            }
            else { // 나머지 요일
                if ( !(i & (1<<6)) && !(i & 1)) {
                    dp[day][nxt|1] = max(dp[day][nxt|1], dp[day-1][i] + arr[day]);
                }
                else dp[day][nxt] = max(dp[day][nxt], dp[day][i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i < (1<<7) ; i++) ans = max(ans, dp[7*(n+1)-1][i]);
    cout << ans;
    return 0;
}