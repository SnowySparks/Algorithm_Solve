#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];
int arr[1001];

int main(void) {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {cin >> arr[i]; dp[i] = arr[i];}
    int ans = 0;
    for (int i = 1 ; i <= N; i++) {
        for (int j = 1 ; j < i; j++) {
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + arr[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
