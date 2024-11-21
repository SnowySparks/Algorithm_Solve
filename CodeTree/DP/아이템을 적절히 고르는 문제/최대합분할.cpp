#include <iostream>
#include <cstring>
#include <algorithm>

#define OFFSET 100000
#define MAX_N 100
#define MAX_M 100000

using namespace std;

int arr[MAX_N+1];
int dp[MAX_N+1][OFFSET + 1 + MAX_M];

//dp[i][j + OFFSET] : i번째 숫자까지 봤을 경우, 그리고 j = sum(a) - sum(b) 인 경우에서
// A가 가질 수 있는 "최대 합"

// n개의 수가 주어졌을 때 이를 정확히 3개의 그룹 A, B, C로 나누어 A에 들어있는 수들의 합과 B에 들어있는 수들의 합이 같아지게 만들 되, 그 합이 최대가 되도록 하는 프로그램을 작성해보세요. 단, 주어진 n개의 수는 각각 A, B 또는 C 중 정확히 한 곳에만 속해야 하며, 아무런 수도 포함하고 있지 않은 그룹 내 수들의 합은 0으로 정의됨에 유의합니다.

int n, m = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(dp, -1, sizeof(dp));

    dp[0][0 + OFFSET] = 0;  
    for (int i = 1; i <= n; ++i ) {
        cin >> arr[i];
        m += arr[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = -m ; j <= m; ++j) {
            // 그룹 A에게 원소 arr[i] 준 경우
            if (j - arr[i] >= -m && dp[i-1][j - arr[i] + OFFSET] != -1) {
                dp[i][j + OFFSET] = max(dp[i][j + OFFSET], dp[i-1][j - arr[i] + OFFSET] +arr[i]);
            } 
            // 그룹 B에게 원소 arr[i] 준 경우
            if (j + arr[i] <= m && dp[i-1][j + arr[i] + OFFSET] != -1) {
                dp[i][j + OFFSET] = max(dp[i][j + OFFSET], dp[i-1][j + arr[i] + OFFSET]);
            } 
            // 그룹 C에게 원소 arr[i] 준 경우
            if (dp[i-1][j + OFFSET] != -1) {
                dp[i][j + OFFSET] = max(dp[i][j + OFFSET], dp[i-1][j + OFFSET]);
            } 

        }
    }

    cout << dp[n][OFFSET];

    return 0;
}