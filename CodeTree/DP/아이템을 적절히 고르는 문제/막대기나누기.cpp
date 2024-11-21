#include <iostream>
#include <cstring>
#include <vector>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
int n, arr[101], dp[101];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 1, n+1) cin >> arr[i];
    f(i, 1, n+1) {
        for (int j = i; j <= n; ++j) {
            dp[j] = max(dp[j], dp[j-i] + arr[i]);
        }
    }
    cout << dp[n];
    return 0;
}