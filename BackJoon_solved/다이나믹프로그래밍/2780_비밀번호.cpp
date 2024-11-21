#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dp[1001][10];
vector<int> adj[10] = {
    {7},
    {2, 4},
    {1, 3, 5},
    {2, 6},
    {1, 5, 7},
    {2, 4, 6, 8},
    {3, 5, 9},
    {0, 4, 8},
    {5, 7, 9},
    {8, 6},
};

int main(void) {
    for (int i = 0 ; i < 10 ; i++) dp[1][i] = 1;

    for (int i  = 2 ; i <= 1000 ; i++) {
        for (int k = 0 ; k < 10 ; k++) {
            for (auto e : adj[k]) {
                dp[i][k] += dp[i-1][e];
            }
            dp[i][k]%=1234567;
        }
    }
    int T; int inp; cin >> T;
    int answer = 0;
    while (T--) {
        cin >> inp;
        answer = 0;
        for (int i = 0 ; i < 10 ; i++) {
            answer+=dp[inp][i];
        }
        answer%=1234567;
        cout << answer << '\n';
    }
    return 0;
}