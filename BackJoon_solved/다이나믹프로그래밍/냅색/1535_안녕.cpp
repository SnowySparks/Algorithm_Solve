#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[21][101];
int hp[21];
int gd[21];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i = 1 ; i <= N ; i++) cin >> hp[i];
    for (int i = 1 ; i <= N ; i++) cin >> gd[i];

    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j < 100 ; j++) {
            if (j - hp[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j - hp[i]] + gd[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[N][99]; return 0;
}