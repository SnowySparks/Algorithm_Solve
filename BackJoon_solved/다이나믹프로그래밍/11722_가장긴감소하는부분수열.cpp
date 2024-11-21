#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001]; //i 인덱스까지의 최대 길이
// 1 ~ i까지의 가장 긴 감소하는 부분 수열의 크기
int arr[1001];

int main(void) {
    int N; cin >> N;
    for (int i = 1 ; i<= N ; i++) {
        cin >> arr[i];
    }

    for (int i = 1 ; i<= N ; i++) {
        dp[i] = 1; //자기자신 
        for (int j = 1 ; j <= i ; j++) {
            // 1 부터 i 까지중 (j) , arr[j] 가 arr[i] 보다 크고, dp[j]값이 적어도 dp[i]와 같거나 클 경우
            //dp[i] 갱신. dp[i]는 항상 최대값을 가지게 됨.
            if (arr[i] < arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << *max_element(dp,dp+N+1);
}