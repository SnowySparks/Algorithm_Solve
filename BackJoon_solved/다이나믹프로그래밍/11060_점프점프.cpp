#include <iostream>
#include <vector>
using namespace std;

int dp[1001];
int arr[1001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i = 1 ; i <= N ; i++) {
        cin >> arr[i];
        dp[i] = 10000;
    }
    dp[N] = 0;
    for (int i = N-1 ; i >= 1; i--) {
        if (arr[i] == 0) continue;
        if (i + arr[i] >= N) dp[i] = 1;
        else {
            for (int k = 1 ; k <= arr[i] ; k++) {
                if (arr[i+k] == 0 || dp[i+k]>=10000) continue;
                dp[i] = min(dp[i], dp[i+k]+1);
            }
        }
    }
    cout << (dp[1] >= 10000 ? -1 : dp[1]); return 0;
}