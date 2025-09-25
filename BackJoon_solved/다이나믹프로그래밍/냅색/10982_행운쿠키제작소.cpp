#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int inf = 2e7;
const int N = 1e3;
const int MAX_TIME = 1e5+1;
int a[N];
int b[N];

int dp[MAX_TIME]; // a에 최대 idx 시간을 부여했을 때, b를 처리하는데 최소 시간

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int T; cin >> T;
    int n;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n;
        int totalA = 0;
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            totalA += a[i];
        }
        for (int i = 1; i <= totalA; ++i) dp[i] = inf; dp[0] = 0;
        
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            tot += a[i];
            for (int j = tot; j >= 0; --j) {
                dp[j] += b[i];
                if (j >= a[i]) dp[j] = min(dp[j], dp[j - a[i]]);
            }
        
        }
        for (int i = 0; i <= totalA; ++i) {
            ans = min(ans, max(i, dp[i]));
        }
        cout << ans << '\n';

    }
    

    return 0;
}