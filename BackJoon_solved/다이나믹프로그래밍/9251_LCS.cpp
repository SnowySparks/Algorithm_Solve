#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 1001

int dp[MAX][MAX];

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    string a,b;
    cin >> a >> b;

    for (int i=1;i<=a.length();i++) {
        for (int k = 1;k<=b.length();k++) {
            if (a[i-1] == b[k - 1]) {
                dp[i][k] =  dp[i-1][k-1] + 1;
            }
            else {
                dp[i][k] = max (dp [i-1][k] , dp[i][k-1]);
            }
        }
    }

    cout << dp[a.length()][b.length()];


    return 0;
}

 