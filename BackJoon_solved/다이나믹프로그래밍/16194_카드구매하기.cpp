#include <iostream>
#include <vector>
#include <algorithm>
#define inf 1<<30
using namespace std;
int main(void) {
    int dp[1001];
    int arr[1001];
    dp[0] = 0;
    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = inf;
    }

    for (int i = 1; i <= N; i++) {
       for (int j = 1 ; j <= i; j++) {
            dp[i] = min(dp[i], dp[i-j] + arr[j]);
       }
    }
    cout << dp[N]; return 0;
}