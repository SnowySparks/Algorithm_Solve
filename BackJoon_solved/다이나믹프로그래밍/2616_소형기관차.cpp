#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++) 
const int inf = 5e5+1;
int n, m;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> arr(n+1,0);
    vector<vector<int> > dp(3, vector<int>(n+1,0));
    f(i,1,n+1) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    cin >> m;
    f(i,m,n+1) dp[0][i] = max(dp[0][i-1],arr[i]-arr[i-m]);
    f(i,2*m,n+1) dp[1][i] = max(dp[1][i-1],dp[0][i-m] + arr[i]-arr[i-m]);
    f(i,3*m,n+1) dp[2][i] = max(dp[2][i-1],dp[1][i-m] + arr[i]-arr[i-m]);
    cout << dp[2][n];
    return 0;
}

