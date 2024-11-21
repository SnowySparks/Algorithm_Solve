#include <iostream>
#include <vector>
using namespace std;
#define f(a,b,c) for (int a = b; a <=c;a++)
int dp[1001][2][3]; //day, 지각횟수, 연속결석횟수
const int mod = 1e6;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    dp[1][0][0] = 1; dp[1][1][0] = 1; dp[1][0][1] = 1;

    f(i,2,n) {
        //today 출석
        f(k,0,1) f(p,0,2) {
            dp[i][k][0] += dp[i-1][k][p];
            dp[i][k][0] %=mod;
        }
        //today 결석
        f(p,0,1) {
            f(k,0,1) {
                dp[i][k][p+1] += dp[i-1][k][p];
                dp[i][k][p+1] %= mod;
            }
            
        }
        //today 지각
        f(p,0,2) {
            dp[i][1][0] += dp[i-1][0][p];
            dp[i][1][0]%=mod;
        }
    }

    int ans = 0;
    f(k,0,1) f(p,0,2) ans += dp[n][k][p];
    cout << ans%mod;
    return 0;
}