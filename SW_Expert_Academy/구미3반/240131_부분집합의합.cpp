#include <iostream>
using namespace std;
using ll = long long;

int num[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int dp[13][79];

int main(void) {
    for(int i = 1 ; i < (1<<12) ; ++i) {
        int cnt = 0, sum = 0;
        for (int j = 0; j < 12; ++j) {
            if (i & (1<<j)) {
                ++cnt; sum+=num[j];
            }
        }
        ++dp[cnt][sum];
    }

    int T,n,k; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n >> k;
        cout <<'#' << t<<' ';
        if (k > 78) cout <<0 <<'\n';
        else cout << dp[n][k] <<'\n';
    }

    return 0;
}