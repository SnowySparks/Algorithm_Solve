#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)
using pii = pair<int,int>; 
const int inf = 1e5+1;
using ll = long long;

ll dp[inf+1][3];
int n;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int cnt = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;
        f(i,0,n) cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
        dp[0][0] = 1e10;
        dp[0][2] += dp[0][1];
        f(i,1,n) {
            dp[i][0] += min(dp[i-1][0],dp[i-1][1]);
            dp[i][1] += min(min(dp[i][0],dp[i-1][0]),min(dp[i-1][1],dp[i-1][2]));
            dp[i][2] += min(min(dp[i][1],dp[i-1][1]),dp[i-1][2]);
        }
    
        cout << cnt << ". " << dp[n-1][1] << '\n';
        cnt++;
    }

    return 0;
}