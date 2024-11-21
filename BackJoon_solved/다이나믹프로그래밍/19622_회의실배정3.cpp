#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long dp[100001];
vector<int> lst[100001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    int s, e, n;
    for (int i = 1; i <= N ; i++) {
        cin >> s >> e >> n;
        lst[i].push_back(s); lst[i].push_back(e); lst[i].push_back(n);
    }

    dp[1] = lst[1][2];

    for (int i = 2 ; i <= N ; i++) {
        dp[i] = max(dp[i-2] + lst[i][2] , dp[i-1]);
    }
    cout << dp[N] << '\n'; return 0;

}