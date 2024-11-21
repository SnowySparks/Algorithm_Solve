#include <iostream>
#include <vector>
#include <algorithm>
#define inf 10000001
using namespace std;

long long dp[1000001];
int arr[1000002][2]; // fun, wait;

//dp[i] : i일 ~ N일째 의 상담의 최대수익
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int min,fun,wait;
    int max_min= 0;
    for (int i = 1 ; i <=N ; i++) {
        cin >> min >> fun >> wait;
        arr[min][0] = fun; arr[min][1] = wait;
        max_min = max(max_min,min);
    }
    for (int i = 1 ; i <= max_min ; i++) {
        arr[i][1] = (arr[i][1] == 0) ? inf : arr[i][1];
    }
    for (int i =  max_min; i>= 1 ; i--) {
        if (i + arr[i][1]<= max_min) { 
            dp[i] = max(dp[i+arr[i][1]] + arr[i][0], dp[i+1]);
        }
        else {
            dp[i] = max(dp[i+1], (long long) arr[i][0]);
        }
    }
    cout << dp[1];
    return 0;
    
}