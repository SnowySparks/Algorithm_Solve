#include <iostream>
#include <algorithm>
#define f(a,b,c) for(int a=b; a<c;a++)
using namespace std;
const int mv = 1e10;

int dt[3][1001];
int dp[3][1001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int ans = mv;
    f(i,1,N+1) cin >> dt[i][0]>>  dt[i][1] >> dt[i][2];
    f(i,0,3) {
        f(k,1,N+1) {
            dp[k][0] = min(dp[k-1][1],dp[k-1][2]) + dt[k][0];
            dp[k][1] = min(dp[k-1][0],dp[k-1][2]) + dt[k][1];
            dp[k][2] = min(dp[k-1][0],dp[k-1][1]) + dt[k][2];
        }

        f(k,0,3) {
            if (i==k) continue;
            ans = min (ans, dp[N][k]);
        }
    }
    cout << ans;
}