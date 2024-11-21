#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];
int arr[1001];

//LIS문제

int main(void) {
    int N ; cin >> N;
    for (int i = 1 ; i <= N ; i++) {
        cin >> arr[i];
    }

    for (int i = 1 ; i <= N ; i++) {
        if (dp[i] == 0) dp[i]  = 1;
        for (int j = 1 ; j <i ; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] < dp[j] +1) dp[i] = dp[j]+1;
            }
        }
    }
    cout << *max_element(dp+1,dp+1+N);

}
