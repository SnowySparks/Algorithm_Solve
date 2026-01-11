#include <iostream>
#include <cstring>
using namespace std;
const int inf = 1'000'000'007;
int n, m, c;
int weight[14];
int dp[1 << 13][10][21]; //선택된 보석 bit, j번째 가방, 담겨진 무게

void input() {
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) cin >> weight[i];
    memset(dp, -1, sizeof(dp));
}

int dfs(int state, int idx, int w) {
    if ( w > c ) return -inf;
    if (state == ((1 << n) -1) || idx == m) return 0;
    
    int &res = dp[state][idx][w];
    if (res != -1) return res;
    res = 0;

    for (int i = 0; i < n; ++i) {
        int target_bit = (1 << i);
        if ( (state & target_bit) != 0 ) continue;

        if ( w + weight[i] > c ) res = max(res, dfs(state, idx + 1, 0));
        else res = max(res, dfs(state | target_bit, idx, w + weight[i] ) + 1);
    }
    return res;
}



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    input();
    cout << dfs(0, 0, 0);
    return 0;
}