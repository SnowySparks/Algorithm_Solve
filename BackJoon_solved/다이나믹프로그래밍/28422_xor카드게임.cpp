#include <iostream>
using namespace std;
const int p = 1e5+1;
#define f(a,b,c) for(int a=b;a<=c;a++)
int dp[p], arr[p];
int n;

int score_cal(int inp) {
    int cnt = 0;
    while (inp) {
        if (inp & 1) cnt++;
        inp /= 2;
    }
    return cnt;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; f(i,1,n) cin >> arr[i];
    if (n == 1) { cout << 0; return 0;}
    dp[2] = score_cal(arr[1] ^ arr[2]);
    dp[3] = score_cal(arr[1] ^ arr[2] ^ arr[3]);
    dp[4] = dp[2] + score_cal(arr[3]^arr[4]);
    if (n <= 4) {cout << dp[n]; return 0;}

    f(i,5,n) dp[i] = max(dp[i-3] + score_cal(arr[i-2]^arr[i-1]^arr[i]) , dp[i-2] + score_cal(arr[i-1]^arr[i]));
    cout << dp[n]; 
    return 0;

}