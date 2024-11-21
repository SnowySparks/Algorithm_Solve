#include <iostream>
#include <vector>
#define f(a,b,c) for (int a =b; a< c;a++)
using namespace std;

int dp[4001][4001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a, b; cin >> a >> b;
    int ans = 0;
    f(i,1,a.size()+1) f(k,1,b.size()+1) {
        if (a[i-1]==b[k-1]) {dp[i][k] = dp[i-1][k-1]+1; ans=max(ans,dp[i][k]);}
    }
    cout << ans; return 0;
}