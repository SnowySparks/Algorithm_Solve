#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e8+1;
int n,m;
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector< vector<int> > dt(n+1, vector<int>(m+1,0));
    for (int i = 1; i <= n ; i++) {
        for (int k = 1 ; k <= m; k++) {
            cin >> dt[i][k];
            if (dt[i][k]) dt[i][k] = inf;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n ; i++) {
        for (int k = 1 ; k <= m; k++) {
            if (dt[i][k] == 0) {
                dt[i][k] = min( min( dt[i-1][k], dt[i][k-1]), dt[i-1][k-1])+1;
                ans = max(ans,dt[i][k]);
            }
        }
    }
    cout << ans; return 0;
}