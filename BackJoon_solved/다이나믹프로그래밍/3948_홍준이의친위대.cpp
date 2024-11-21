#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//지그재그 순열 증가 - 감소 - 증가 -감소 or 감소 - 증가 - 감소 - 증가 
long long dp[21][21];
//Euler Zigzag Number 
long long zigzag(int n , int k) {
    if (k==0) {
        if (n == 0 ) return 1;
        else return 0;
    }

    if (dp[n][k]!= -1) return dp[n][k];
    return dp[n][k] = zigzag(n,k-1) + zigzag(n-1,n-k);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 1;
    int T; cin >> T;
    while(T--) {
        int cnt ; cin >> cnt;
        if (cnt == 1) {cout << 1 <<'\n'; continue;}
        cout << zigzag(cnt,cnt) * 2 << '\n';
    }
    return 0;
}