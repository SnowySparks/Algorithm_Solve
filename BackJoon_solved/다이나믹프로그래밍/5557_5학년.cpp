#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101];
long long dp[101][21];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    dp[0][arr[0]] = 1;
    int value;
    for (int i = 1 ; i < N-1; i++) {
        for (int j = 0 ; j <= 20 ; j++) {
            value = j - arr[i];
            if (value >= 0 && value <= 20) dp[i][value]+=dp[i-1][j];
            value = j + arr[i];
            if (value >= 0 && value <= 20) dp[i][value]+=dp[i-1][j];     
        }
    }
    cout << dp[N-2][ arr[N-1]];
    return 0;
}