#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#define INF 20000
using namespace std;
long long dp[20000];

bool comp(const vector<int> &a, const vector<int> &b) {
    return (a[0]+a[1] < b[0]+b[1]);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector <vector <int> > dt;
    int T; cin >> T;
    int N;
    int s,d,w;

    while (T--) {
        cin >> N; int n = N;
        while (n--) {
            cin >> s>> d >>w;
            dt.push_back({s,d,w});
        }
        sort(dt.begin(),dt.end(),comp);
        dp[0] = 0;
        for (int t = 1, i = 0 ; t <= 10080 ; t++) {
            dp[t] = dp[t-1];
            while (i < N && dt[i][0] + dt[i][1] == t) {
                dp[t] = max(dp[t] , dp[dt[i][0]] + dt[i][2]);
                i++;
            }
        }
        cout << dp[10080] <<'\n';
        dt.clear();
    }
    return 0;
}