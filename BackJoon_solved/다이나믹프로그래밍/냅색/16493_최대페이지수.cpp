#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)
int n, m;
int dp[21][201];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector< vector<int> > dt(m+1, vector<int>(2));
    f(i,1,m+1) cin >> dt[i][0] >> dt[i][1];

    f(i,1,m+1) {
        f(j,1,n+1) {
            if (j >= dt[i][0]) dp[i][j] = max(dp[i-1][j - dt[i][0]] + dt[i][1], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[m][n];
    return 0;

}