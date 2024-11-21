#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define f(a,b,c) for (int a=b; a<c;a++)
const short inf =32000;
short dp[5000][5000];
int arr[5000];
int n;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    f(i,0,n) cin >> arr[i];
    f(i,0,n) {
        f(j,0,n) {
            dp[i][j] = inf;
        }
        dp[i][i] = 0;
        if (i < n-1) {
            if (arr[i]==arr[i+1]) dp[i][i+1] = 0;
            else dp[i][i+1] = 1;
        } 
    }

    for (int len = 2; len < n ; len++) {
        for (int st = 0 ; len+st < n; st++) {
            short &res = dp[st][st+len];
            if (arr[st] == arr[st+len]) res = dp[st+1][st+len-1];
            else res = min(dp[st][st+len-1], dp[st+1][st+len])+1;
        }
    }
    cout << dp[0][n-1];
    return 0;
    
}