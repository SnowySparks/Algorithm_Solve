#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool dp[51][1001]; 
int main (void ) {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);
    int N, S, M; cin >> N >> S >> M;
    dp[0][S] = true;
    int inp;
    for (int i = 1 ; i <= N ; i++) {
        cin >> inp;
        for (int p = 0 ; p <= M ; p++) {
            if (dp[i-1][p] == true) {
                if (p-inp >= 0) dp[i][p-inp] = true;
                if (p+inp <= M) dp[i][p+inp] = true;
            }
        }
    }
    for (int i = M ; i >= 0 ; i--) {
        if (dp[N][i] == true) {
            cout << i ;
            return 0;
        }
    }
    cout << -1; return 0;
}