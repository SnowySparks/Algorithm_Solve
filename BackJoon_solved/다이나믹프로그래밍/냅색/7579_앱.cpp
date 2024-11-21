#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define inf 2000000000

using namespace std;

int dp[101][10001]; // i번째 앱까지 확인  j비용으로 얻을 수 있는 최대 메모리
int m[101];
int c[101];
int sum = 0;
int ans = 0;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M,ans;
    cin >> N >> M;

    for (int i = 1 ; i<= N ; i++) {
        cin >> m[i];
    }
    //최대 비용 소요시간 
    for (int i = 1 ; i<=N ; i++) {
        cin >> c[i];
        sum += c[i];
    }

    //dp연산을 이용하여, (i,j) 위치의 최대 메모리값 구하기.
    for (int i = 1 ; i<=N ; i++) {
        for (int j = 0 ; j <= sum ; j++) {
            if (j - c[i] >= 0) {
                dp[i][j] = max(dp[i][j],dp[i-1][j-c[i]]+m[i]);
            }
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }

//dp는 [i]값이 커질수록 값이 커지는 구조이므로, 처음 memory값 이상이 될 때만 조치
    for (int i = 0; i <= sum ; i++) {
        if (dp[N][i] >= M) {
            cout << i;
            break;
        }
    }
    return 0;
}