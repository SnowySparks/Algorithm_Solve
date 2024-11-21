
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define f(a,b,c) for(int a=b; a<=c; a++)
#define ff(a,b,c) for(int a=b; a>=c; a--)
const int p = 1e3+1;
const int minv = -1e8;
int dp[p][p];
int l[p];
int r[p];
int n, m;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f(i,1,n) f(j,1,m) cin >> dp[i][j];
    f(i,2,m) dp[1][i] += dp[1][i-1]; //first line
    f(i,2,n) { // from 2 row
        l[1] = dp[i-1][1] + dp[i][1];
        r[m]  = dp[i-1][m] + dp[i][m];
        f(k,2,m) l[k] = max(l[k-1], dp[i-1][k]) + dp[i][k];
        ff(k,m-1,1) r[k] = max(r[k+1], dp[i-1][k]) + dp[i][k];
        f(k,1,m) dp[i][k] = max(l[k],r[k]);
    }
    cout << dp[n][m]; 
    return 0;

}