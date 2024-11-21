#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1e6+7;
#define f(a,b,c) for(int a = b ; a <= c; a++) 

int n, m, c;

int gh[51][51];
int dp[51][51][51][51]; // row, column 현재 가장 최대 오락실 번호  현재 거친 오락실수

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> c;
    f(i,1,c) {
        int a,b; cin >> a >> b;
        gh[a][b]=i;
    }

    if (gh[1][1]) dp[1][1][gh[1][1]][1] = 1;
    else dp[1][1][0][0] = 1;

    f(i,1,n) f(j,1,m) {
        if (i==1 && j ==1) continue; // skip
        if (gh[i][j] == 0) {
            f(t,0,c) f(k,0,t) { //t : 최대 오락실 번호 , k : 최대 거친 오락실 수
                dp[i][j][t][k] += dp[i-1][j][t][k] + dp[i][j-1][t][k];
                dp[i][j][t][k]%=mod;
            }
        }
        else {
            f(k,0,gh[i][j]-1) { // 미방문 ~ gh[i][j] - 1까지 번호
                f(t,0,k) { // 거친 횟수 : 최소 0회 , 최대 gh[i][j]-1번호
                    dp[i][j][gh[i][j]][t+1] += dp[i-1][j][k][t] + dp[i][j-1][k][t];
                    dp[i][j][gh[i][j]][t+1] %= mod; }
            }
        }
    }


    

    f(i,0,c) {
        int sum = 0;
        f(t,0,c) {
            sum+= dp[n][m][t][i];
            sum%=mod;
        }
        cout << sum <<' ';
    }
    return 0;

}