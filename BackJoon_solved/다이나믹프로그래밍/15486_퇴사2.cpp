#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1500002];
int arr[1500001][2]; // T , P

//dp[i] : i일 ~ N일째 의 상담의 최대수익
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    
    for (int i = 1 ; i <=N ; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    //N +1 일째엔 퇴사 : 즉 N일 째는 반드시 일을 못함.
    //역으로 N에서 감소를 하면서 조건충족 하는지 판별
    for (int i = N ; i>= 0 ; i--) {
        if (i + arr[i][0] -1 <= N) { 
            //현재 날짜 + 걸리는 날짜 - 1 : 그 일이 끝나는 날짜
            //성립시, 다음 날짜의 최대 수익을 그대로 가져오거나, i+arr[i][0] 일째의 최대수익 + 당일 수익 둘중 최대값을 적용
            dp[i] = max(dp[i+arr[i][0]] + arr[i][1], dp[i+1]);
        }
        //성립 안하면, 다음 날짜의 최대 수익을 그대로 가져옴
        else {
            dp[i] = dp[i+1];
        }
    }
    cout << dp[1];
    return 0;
    
}