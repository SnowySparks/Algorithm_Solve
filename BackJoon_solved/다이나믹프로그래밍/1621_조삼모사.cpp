#include <iostream>
#include <vector>
#include <algorithm>
#define f(a,b,c) for (int a = b; a <= c; a++)
using namespace std;
const int mt = 1E6+4;
int N, K,C;
int dt[mt];
int dp[mt];
int nxt[mt];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> K >> C;
    f(a,1,N) cin >> dt[a];
    for(int i = N; i >=1; i--) {
        if ((i < N-(K-2)) && dp[i+K] + C < dp[i+1] + dt[i]) {
            dp[i] = dp[i+K] + C;
            nxt[i] = i+K;
        }
        else {
            dp[i] = dp[i+1] + dt[i];
            nxt[i] = i+1;
        }
    }
    cout << dp[1] <<'\n';
    vector<int> tp;
    int lst = 1;
    while( lst <= N) {
        if (nxt[lst] - lst == K && dp[lst] - dp[nxt[lst]] != dt[lst]) tp.push_back(lst);
        lst = nxt[lst];
    }
    cout << tp.size() << '\n';
    for (auto e : tp) cout << e << '\n'; 
    return 0;
}