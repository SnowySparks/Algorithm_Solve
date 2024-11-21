#include <iostream>
#include <vector>
#include <algorithm>
#define dv 1000000007
using namespace std;

long long dp[101][101][101]; //개수, 왼쪽에서 바라보면 , 오른쪽에서 바라보면
// N = 3 -> 4로 갈때 세워진 모든 빌딩 +1 높이 한다고 가정하고 가장 작은 빌딩을 놓는다고 생각
int N;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int L, R; cin >> L >> R;
    dp[1][1][1] = 1;
    dp[2][2][1] = 1; dp[2][1][2] = 1;
    for (int i = 3 ; i <= N ; i++) { // i번 높이 빌딩 놓는 상황
        for (int l = 1; l <= i ; l++) { 
            for (int r = 1; r <= i ; r++) {
                dp[i][l][r] = dp[i-1][l-1][r] + dp[i-1][l][r-1] + dp[i-1][l][r]*(i-2);
                dp[i][l][r] %= dv;
            }
        }
    }
    cout << dp[N][L][R] <<'\n'; return 0;
}