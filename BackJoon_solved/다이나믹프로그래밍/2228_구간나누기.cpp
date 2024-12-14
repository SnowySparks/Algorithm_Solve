#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9 + 7;

#define IN 1
#define NOT_IN 0

int dp[51][101][2]; // dp[j][i][k]; 
// j개 구간에 i 위치까지 있을 때 구간별 총 합 최대값, k : i 위치는 j번째 그룹에 속했는가?

int arr[101];
int prefix[101];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i <= n; ++i) for (int j = 0; j <= m; ++j) {
        dp[j][i][NOT_IN] = -inf;
        dp[j][i][IN] = -inf;
    }
    for (int i = 0; i <= n; ++i) dp[0][i][NOT_IN] = 0;

    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            // i번째 위치에 원소가 j번째 그룹에 속할 경우, 그룹끼리의 총 합 최대값
            dp[j][i][IN] = max(dp[j][i-1][IN] + arr[i], dp[j-1][i-1][NOT_IN] + arr[i]);

            // i번째 위치에 원소가 j번째 그룹에 속하지 않는 경우, 그룹끼리의 총 합 최대값
            dp[j][i][NOT_IN] = max(dp[j][i-1][IN], dp[j][i-1][NOT_IN]);
        }
    }
    cout << max(dp[m][n][NOT_IN], dp[m][n][IN]) << '\n';

    return 0;
}