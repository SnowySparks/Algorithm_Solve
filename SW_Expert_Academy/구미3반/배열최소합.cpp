#include <iostream>
#include <cstring>
using namespace std;
int n;
const int inf = 1e9+10;
int dp[1<<10];
int arr[10][10];

int tsp(int cur, int state) {
    if (state == (1<<n)-1) return 0;
    int &res = dp[state];
    if (res != -1) return res;
    res = inf;

    for (int i = 0; i < n ; ++i) {
        if (state & (1<<i)) continue;
        res = min(res, tsp(cur+1,state|(1<<i)) + arr[cur][i]);
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>arr[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        cout << '#' <<tc <<' ' << tsp(0,0) <<'\n';
    }
    return 0;
}