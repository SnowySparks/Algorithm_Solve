#include <iostream>
#include <vector>
#include <algorithm>

#define inf 1000000000

using namespace std;


int dp[501][501];// i ~ k 까지 행렬곱 최소 연산 횟수 저장
pair<int, int> arr[501];// 각 행렬 행,열 저장


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N,r,c;
    cin >> N;
    for (int i = 1 ; i <= N ; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 1 ; i < N ; i++) { // 최소 2개의 곱이므로 i < N 이어야한 한다.
        for (int j = 0 ; j+i <= N ; j++) { 
            dp[j][j+i] = inf;
            for (int p = j; p < j+i ; p++) {
                //행렬식 j ~ j+1 의 최소연산 = min (기존 , j ~ p 와 p+1 ~j+1 연산 합 이후, 그 2개의 행렬곱 연산 횟수 )
                dp[j][j+i] = min (dp[j][j+i] , dp[j][p] + dp[p+1][j+i] + (arr[j].first * arr[p].second * arr[i+j].second));
            }
        }
    }

    cout << dp[1][N];
    return 0;
}