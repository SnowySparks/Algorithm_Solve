#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[201];
int arr[201];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int ans = 0;
    int N; cin >>N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1 ; i <= N ; i++) {
        dp[i] = 1;
        for (int j = 1; j<i ; j++) {
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    cout << N-ans;
    return 0;
}