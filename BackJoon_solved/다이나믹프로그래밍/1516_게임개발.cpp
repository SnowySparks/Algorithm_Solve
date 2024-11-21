#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define inf 10000000
using namespace std;

vector<int> gh[501];
int cost[501];
int inDegree[501];
int dp[501];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    int temp;
    for (int i = 1 ; i <= N ; i++) {
        dp[i] = 0;
        cin >> cost[i];
        while(true) {
            cin >> temp;
            if (temp == -1) break;
            inDegree[i]++;
            gh[temp].push_back(i);
        }
    }
    queue<int> lst;
    for (int i = 1; i <= N ; i++) {
        if (inDegree[i] == 0) {lst.push(i); dp[i] = cost[i];}
    }

    while(!lst.empty()) {
        int loc = lst.front(); lst.pop();
        for (int e : gh[loc]) {
            dp[e] = max(dp[e],dp[loc] + cost[e]);
            inDegree[e]--;
            if (inDegree[e] == 0) lst.push(e);
        }
    }
    for (int i = 1 ; i <= N ; i++) {
        cout << dp[i] << '\n';
    } return 0;
}