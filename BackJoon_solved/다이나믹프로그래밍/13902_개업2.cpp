#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, m; cin >> N >> m;
    vector<int> arr(m);
    fill (dp+1, dp+1+N, 1 << 30);
    for (int i = 0; i <m; i++) {cin >> arr[i]; dp[arr[i]] = 1; }
    for (int i = 0; i <m-1; i++) {
        for (int j = i+1; j < m; j++) {
            if (arr[i] + arr[j] <= N) {
                arr.push_back(arr[i] + arr[j]);
                dp[ arr[i] + arr[j]] = 1;
            }
        }
    }

    sort(arr.begin(), arr.end(),greater<>());
    for (int i = 1 ; i <= N ; i++) {
        if (dp[i] == 1) continue;
        for (int k = 0 ; k  < arr.size() ; k++) {
            if (i- arr[k] <= 0) continue;
            if (dp[i-arr[k]] == -1) continue;
            
            dp[i] = min(dp[i-arr[k]]+1, dp[i]);
        }
    }
    cout << (dp[N] >= 1 <<30 ? -1 : dp[N]); return 0;
}