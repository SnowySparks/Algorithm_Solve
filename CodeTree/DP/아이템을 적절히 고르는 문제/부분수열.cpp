#include <iostream>
#include <vector>
using namespace std;
#define f(a, b, c) for(int a=b;a<c;++a)
int dp[10001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int inf = 1e9;
    int n, m;
    cin >> n >> m;
    f(i, 1, m+1) dp[i] = inf;
    int val;
    f(i, 0, n) {
        cin >> val;
        for (int j = m; j >= val; --j) {
            dp[j] = min(dp[j], dp[j - val] + 1);
        }
    }
    cout << (dp[m] == inf ? -1 : dp[m]);
    return 0;
}