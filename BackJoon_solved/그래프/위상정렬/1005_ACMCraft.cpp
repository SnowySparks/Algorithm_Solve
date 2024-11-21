#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int inDegree[1001];
vector<int> gh[1001];
int cost[1001];
int dp[1001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    int N, K; //개수 ,순서개수
    int final_loc;
    int a,b;

    while(T--) {
        cin >> N >> K;
        for (int i = 1 ; i <= N ; i++) {
            cin >> cost[i];
        }
        for (int i = 0 ; i <K ; i++) {
            cin >> a >>b;
            gh[a].push_back(b);
            inDegree[b]++;
        }
        cin >> final_loc;
        queue<int> q;
        for (int i = 1 ; i<= N ; i++) {
            if (inDegree[i] == 0) q.push(i);
            dp[i] = cost[i];
        }

        while (!q.empty()) {
            int loc = q.front(); q.pop();
            for (auto e : gh[loc]) {
                dp[e] = max(dp[e] , dp[loc] + cost[e]);
                inDegree[e]--;
                if (inDegree[e] == 0) q.push(e);
            }
        }
        cout << dp[final_loc] <<'\n';
        for (int i = 0 ; i <= N ; i++) {
            gh[i].clear();
            inDegree[i] = 0;
            dp[i] = 0;
        }
    }
    return 0;
}