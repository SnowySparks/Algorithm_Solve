#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long _inf = 1e15;
int dp[101];


int main(void) {
    for (int i = 1 ; i <= 100 ; i++) {
        dp[i] = dp[i-1]+1;
    }
    for (int i = 1 ; i <= 100 ; i++) {
        if (i - 10 >= 0) dp[i] = min(dp[i],dp[i-10]+1);
        if (i - 25 >= 0) dp[i] = min(dp[i],dp[i-25]+1);
    }

    int T; cin >> T;
    long long N,temp, ans=0;
    while(T--) {
        cin >> N;
        while (N>0) {
            temp = N%100;
            ans+=dp[temp];
            N/=100;
        }
        cout << ans << '\n';
        ans = 0;
    }
    
    return 0;

}