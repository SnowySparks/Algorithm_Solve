#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dp[10001];
int indeg[10001];
vector<pair<int, int> > gh[10001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    while(M--) {
        int s, e, w; cin >> s >> e >> w;
        gh[s].push_back({e,w});
        indeg[e]++;
    }
    queue<int> q;
    for (int i = 1 ; i <= N; i ++) {
        if (indeg[i]==0) {
            q.push(i);
            dp[i] = 1;
        }
    }
    int ans = -1;
    while (!q.empty()) {
        int loc = q.front(); q.pop();
        for (auto e : gh[loc]) {
            int nxtday = dp[loc] + (e.second >=7 ? e.second +1 : e.second) ;
            dp[e.first] = max(dp[e.first],nxtday);
            ans = max(ans,dp[e.first]);
            indeg[e.first]--;
            if (indeg[e.first] == 0) q.push(e.first);
        }
    }
    
    cout << ans;
    return 0;
}