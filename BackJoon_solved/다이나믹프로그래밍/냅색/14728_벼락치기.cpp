#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][10001];

int score[101];
int times[101];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,T ; cin >> N >> T;
    int inp1, inp2;
    for (int i = 1 ; i <=N ; i++) {
        cin >> times[i] >> score[i];
    }
    
    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j <=T ; j++) {
            if (j>=times[i]) dp[i][j] = max(dp[i-1][j],dp[i-1][j-times[i]]+score[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[N][T];
    return 0;
}