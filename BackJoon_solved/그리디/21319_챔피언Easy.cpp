#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 2e5+1;
int n;
int arr[MAXN];
int dp[MAXN]; // i번째 선수기준 오른쪽 선수들 중 보정치를 적용한, 가장 높은 운동능력치
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    if (n == 1) {
        cout << 1;
        return 0;
    }
    dp[n] = arr[n];
    for (int i = n-1; i >= 1; --i) dp[i] = max(dp[i+1]-1, arr[i+1]);
    bool isYes = false;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] > arr[i-1]) {
            int t = arr[i] + i - 1;
            if (t > dp[i]) {
                isYes = true;
                cout << i << ' ';
            }
        }
    }
    if (!isYes) cout << -1;

    return 0;
}