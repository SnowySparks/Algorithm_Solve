#include <vector>
#include <iostream>
using namespace std;

int dp[100001][2];
int arr[100001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    for (int i = 1 ; i <= N ; i++) {
        cin >> arr[i];
    }
    int answer = arr[1];
    dp[1][1] = arr[1]; dp[1][0] = arr[1];

    for (int i = 2 ; i <= N ; i++) {
        dp[i][0] = max(dp[i-1][0] + arr[i] , arr[i]);//제거고려x식
        dp[i][1] = max (dp[i-1][0] , dp[i-1][1] + arr[i]); //제거고려
        //이전 연속합을 가져오거나, 이미 한번 뺀 것에서 현재 arr을 가져고어나
        answer = max(answer , max(dp[i][0],dp[i][1]));
    }    
    cout << answer ;
    return 0;
}