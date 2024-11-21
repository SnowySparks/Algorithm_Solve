#include <iostream>
#include <vector>
using namespace std;

long long dp[1000001];
 
int main(void) {
    int n; cin >> n;
    dp[1] = 1; dp[0] = 0;
    for (int i = 2; i<= abs(n); i++) {
        dp[i] = (dp[i-1] + dp[i-2])%1000000000;
    }

    if (n > 0) {
        cout << 1 <<'\n';
        cout << dp[n];
        return 0;
    }
    else if (n < 0) {
        cout << (abs(n) % 2 == 1 ? 1 : -1) << '\n';
        cout << (abs(n) % 2 == 1 ? dp[abs(n)] : (-1 * dp[abs(n)]));
        return 0;
    }
    else {
        cout <<0 <<'\n';
        cout << 0;
        return 0;
    }
}