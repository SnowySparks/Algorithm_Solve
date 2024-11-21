#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = unsigned long;
ll dp[1001];
int N;
string inp;
const ll inf = 1E14;
char t[3] = {'B', 'O', 'J'};
int ci (char c) {
    return (c =='B') ? 0 : ( (c =='O') ? 1 : 2); }

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N; cin >> inp;
    fill(dp, dp+N, inf); dp[0] = 0;

    for (int i = 0 ; i < N-1 ; i++) {
        for (int j = i+1; j < N ; j++) {
            if ((ci(inp[i]) + 1)%3 == ci(inp[j]) ) {
                dp[j] = min(dp[j] , dp[i] + (j-i)*(j-i));
            }
        }
    }
    if (dp[N-1] > 1000000) cout<<"-1";
    else cout << dp[N-1];
    return 0;
}
