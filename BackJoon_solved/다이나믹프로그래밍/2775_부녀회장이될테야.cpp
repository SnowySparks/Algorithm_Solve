#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[15][15];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin>> N;
    
    int a,b;
    for (int i = 0 ; i <= 14; i++) {
        for (int j = 1 ; j <= 14 ; j ++) {
            if (i==0) dp[i][j] = j;
            else {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
    }
    
    while (N--) {
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
    return 0;
}