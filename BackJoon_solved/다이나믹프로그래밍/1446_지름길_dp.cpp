#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10005];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, D; cin >> N >> D;
    vector<pair<int ,pair<int ,int> > > dts;
    int start, end , dist;
    for (int i = 0 ; i < N ; i++) {
        cin >> start >> end >> dist;
        if (end > D || end -start < dist) continue;
        dts.push_back(make_pair(end, make_pair(start, dist)));
    }
    sort(dts.begin(), dts.end());
    dist = 0;
    for (int i = 0, p = 1; p <= D ; p++) {
        dp[p] = dp[p-1] + 1;
        while (i < dts.size() && dts[i].first == p) {
            dp[p] = min (dp[p] , dp[dts[i].second.first] + dts[i].second.second);
            i++;
        }
    }
    cout << dp[D] <<'\n';
    return 0;
}