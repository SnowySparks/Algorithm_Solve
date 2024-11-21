#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[3][32][32]; //가로 - 대각선 - 세로 방식
int maps[32][32];

int main(void) {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maps[i][j];
        }
    }
    //1행 (2열 ~ N열) 까지 전부 가로 경우 1 설정, 단 벽 고려
    dp[0][0][1] = 1;
    for (int i = 2 ; i < N; i++) {
        if (maps[0][i] == 0) dp[0][0][i] = dp[0][0][i-1];
    }

    for (int i = 1 ; i < N; i++) {
        for (int j = 1; j < N; j++) {
            //대각선
            if (maps[i][j] == 0 && maps[i-1][j] == 0 && maps[i][j-1] == 0) {
                dp[1][i][j] = (dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1]);
            }
            //가로 & 세로
            if (maps[i][j] == 0) {
                dp[0][i][j] = (dp[0][i][j-1] + dp[1][i][j-1] );
                dp[2][i][j] = (dp[2][i-1][j] + dp[1][i-1][j]) ;
            }
        }
    }
    cout << dp[0][N-1][N-1] + dp[1][N-1][N-1] + dp[2][N-1][N-1] ;
    return 0;

}