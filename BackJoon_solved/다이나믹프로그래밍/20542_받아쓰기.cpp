#include <iostream>
#include <vector>
#include <cstring>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;

int n, m;
string input, ans;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> input;
    cin >> ans;
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    f(i, 1, n+1) dp[i][0] = i;
    f(j, 1, m+1) dp[0][j] = j;

    f(i, 1, n+1) {
        f(j, 1, m+1) {
            if (input[i-1] == ans[j-1]) dp[i][j] = dp[i-1][j-1];
            else if (input[i-1] == 'i' && (ans[j-1] == 'j' || ans[j-1] == 'l')) dp[i][j] = dp[i-1][j-1];
            else if (input[i-1] == 'v' && ans[j-1] == 'w') dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
        }
    }
    cout << dp[n][m];
    return 0;
}