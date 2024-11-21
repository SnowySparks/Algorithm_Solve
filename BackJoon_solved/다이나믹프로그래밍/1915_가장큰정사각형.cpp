#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[1001][1001];
string str[1001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> str[i];
        str[i] = "0" + str[i];
    }
    int answer = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1 ; j<=m; j++) {
            if (str[i][j] == '1') {
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1])) +1;
                answer = max(answer,dp[i][j]);

            }
        }
    }
    cout <<  answer*answer; return 0;
}

/*
01100
01110
01110
00110
*/