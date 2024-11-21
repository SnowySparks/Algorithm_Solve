#include <iostream>
#include <vector>
#include <algorithm>
#define inf (int)500001
#define md 1000000007
using namespace std;

int arr[inf];
long long adddp[inf];
long long dp[inf];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i = 1 ; i<= N ; i++) {
        cin >> arr[i];
        adddp[i] = adddp[i-1]+arr[i];
    }

    for (int i = 2 ; i<= N ; i++) {
        dp[i] = dp[i-1] + adddp[i-1]*arr[i];
        dp[i]%=md;
    }
    cout << dp[N]; return 0;
}