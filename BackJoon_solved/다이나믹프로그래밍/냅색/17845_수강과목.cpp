#include <iostream>
#include <vector>
#include <algorithm>
#define f(a,b,c) for(int a = b; a <= c ; a++)
using namespace std;

int dp[1001][100001];
int dt[1001][2];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K; cin >> N >> K;
    f(i,1,K) cin >> dt[i][0] >> dt[i][1];
    f(i,1,K) {
        f(j,1,N) {
            if (j >= dt[i][1]) dp[i][j] = max(dp[i-1][j], dp[i-1][j - dt[i][1]] + dt[i][0]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout <<dp[K][N]; return 0;
}
