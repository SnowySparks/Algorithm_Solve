#include <string>
#include <vector>
using namespace std;
const int inf = 1e9+7;
const int mv = 3e5+1;
int dp[mv][2]; //해당 번호가 참가를 안했을 경우 (0), 했을경우(1) 에 대한 것

vector<int> gh[mv];

void dfs(int loc,const vector<int> &arr) {
    dp[loc][0] = 0;
    dp[loc][1] = arr[loc-1];
    if (gh[loc].empty()) return;
    int diff = inf;
    for(int child : gh[loc]) {
        dfs(child,arr);
        if (dp[child][0] < dp[child][1]) {
            dp[loc][0] += dp[child][0];
            dp[loc][1] += dp[child][0];
            diff = min (diff, dp[child][1] - dp[child][0]);
        }
        else {
            dp[loc][0] += dp[child][1];
            dp[loc][1] += dp[child][1];
            diff = 0;
        }
    }
    dp[loc][0] += diff;
    return ;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    for(vector<int> e : links) {
        gh[e[0]].push_back(e[1]);
    }
    dfs(1,sales);
    return min(dp[1][0],dp[1][1]);
}