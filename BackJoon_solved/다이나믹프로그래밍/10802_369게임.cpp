#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e5+2; // 10^ 100000 반영
int mod = 20150523;

int dp[3][inf] // [last number][10^n] 
// 0 도 3의 배수이다. --> 120 ~ 129 같은 특이 케이스 고려


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    dp[0][0] = 1; dp[0][3] = 1; dp[0][6] = 1; dp[0][9] = 1; dp[1][0] = 4;
    for (int idx = 1; i < inf-1 ; i++) { //idx == 10^idx
        for (int j = 1; j <= 9 ; j++) { // j =-> jxxxx
            if (j%3==0) { // 3배수 --> 그냥 10배
                dp[idx][j] = dp[idx-1][j] * 10 % mod;
            }
            else { //아닌것들
                for (int k = 0; k <= 9; k++) {
                    if (k%3) dp[idx][j] += (dp[idx-1][(k+j)%3]);
                    else dp[idx][j] += dp[idx-1][k];
                    dp[idx][j]%=mod;
                }
            }
        }
    }


    return 0;
    
}