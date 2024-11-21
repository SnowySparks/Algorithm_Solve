#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[2001];
int dp[2001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;

    for (int i = 1 ; i <= N ; i++) {
        cin >> arr[i];
    }

    for (int i = 1 ; i <= N ; i++) {
        dp[i] = 1;
        for (int j = 1 ; j < i ; j ++) {
            if (arr[i] < arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << N - *max_element(dp,dp+1+N);

}