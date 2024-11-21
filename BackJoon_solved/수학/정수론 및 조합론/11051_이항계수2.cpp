#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dp[1001][1001];


int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,k;
    cin >> n >> k;

    for (int i=1; i<= n ; i++) {
         for (int j= i ; j >=0 ;j--) {
            if (i==j || j==0) {
                dp[i][j] = 1;
            }
            else if (j!=1) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007;
            }
            else {
                dp[i][j] = i;
            }
         }
    }

    cout << dp[n][k];

   

    return 0;

    

}