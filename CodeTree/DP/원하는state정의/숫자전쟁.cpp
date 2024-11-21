#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_n = 1001;

int n;
int a[max_n];
int b[max_n];
int dp[max_n][max_n]; //현재 첫번째는 i, 두번째 플레이어는 j 번째 카드를 바라보기 전 가질 수 있는 최대 값

int dfs(int aloc, int bloc) {
    if (aloc == n || bloc == n) return 0;
    int &res = dp[aloc][bloc];
    if (res != -1) return res;
    res = dfs(aloc + 1, bloc + 1);
    if (a[aloc] > b[bloc]) res = max(res, dfs(aloc,bloc+1) + b[bloc]);
    else if (a[aloc] < b[bloc]) res = max(res, dfs(aloc+1,bloc));
    return res;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i <n; ++i) cin >>a[i];
    for (int i = 0; i <n; ++i) cin >>b[i];
    cout << dfs(0, 0);

    return 0;
}