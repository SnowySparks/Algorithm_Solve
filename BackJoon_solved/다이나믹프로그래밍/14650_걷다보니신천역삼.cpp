#include <iostream>
#include <vector>
using namespace std;
long long dp[33334];
const int dv = 1E9+9;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    dp[1] = 0; dp[2] = 2;
    for (int i = 3; i <= N; i++) dp[i] = dp[i-1]*3%dv;
    cout << dp[N]; return 0;
}