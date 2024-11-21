#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_ten = 1e5 + 2;
const long long mod = 1e9 + 7;
using ll = long long;
ll ten[max_ten]; // 10^(idx) % mod
ll dp[max_ten][3]; // i 자리 (10^(i-1) ) 이고 첫 숫자가 0, j%3 != 0, j%3 == 0 인 경우 각각 박수 치는 횃수
// j = 1 는 첫 숫자가 1,2,4,5,7,8 6개
// j = 0은 첫 숫자가 0 
// j = 2 는 첫 숫자가 3, 6, 9
string s;
int length;

ll cal() {
    ll ans = 0;
    int length = s.size();
    for (int i = 0; i < length; ++i) {
        
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    length = s.size();
    ten[1] = 1;
    for (int i = 2; i <= length; ++i) ten[i] = (ten[i-1]*10)%mod;
    dp[0][0] = 1; 
    dp[1][0] = 1; dp[1][1] = 0; dp[1][2] = 1;
    for (int i = 2; i <= length; ++i) {
        dp[i][2] = dp[i-1][2]*10 % mod;
        dp[i][0] = (dp[i-1][0] + dp[i-1][2]*3 + dp[i-1][1]*6)%mod;
        dp[i][1] = ((dp[i-1][0] + dp[i-1][1] + dp[i-1][2])*3 + dp[i-1][1])%mod;
    }

    return 0;
}