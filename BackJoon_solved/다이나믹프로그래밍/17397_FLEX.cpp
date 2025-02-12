#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int arr[1001];
int dp[1001][201][11]; //i번째 날에, 남은여유 돈이 j이고, 직전에 k만큼 사용했을때 얻을 수 있는 박탈감 최소
const int inf = 1e9 + 7;

int dfs(int day, int leftMoney, int beforeSpent) {
    if (day == n+1) return 0;
    int &res = dp[day][leftMoney][beforeSpent];
    if (res != -1) return res;
    res = inf;
    for (int i = arr[day]; i <= 10; ++i) {
        int moreSpendMoney = i - arr[day];
        if (leftMoney < moreSpendMoney) break;
        res = min(res, dfs(day+1, leftMoney-moreSpendMoney, i) + (beforeSpent <= i ? 0 : (i-beforeSpent)*(i-beforeSpent)));
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, m, 0);
    return 0;
}