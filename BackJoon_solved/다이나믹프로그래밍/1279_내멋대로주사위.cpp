#include <iostream>
#include <algorithm>
using namespace std;
#define f(a,b,c) for(int a= b; a <= c; a++)
const int mov = 1e9+7;

int dp[7][6000001];
int m;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m;
    f(i,1,m) dp[i][m] = i;

    f(i, 2, 6) {
        int st = i*(i+1)/2;
        f(k,st,m) {
            dp[i][k] = dp[i-1][k-1];
        }
    }
}