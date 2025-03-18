#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[101][2][21];
char target[22];
char bridge[2][102];

int targetSize = 0;
int bridgeSize = 0;

int dfs(int loc, int type, int targetLoc) {
    if (targetLoc == targetSize) return 1;
    if (loc == bridgeSize && targetLoc < targetSize) return 0;
    int &res = dp[loc][type][targetLoc];
    if (res != -1) return res;
    res = 0;

    for (int i = loc+1; i <= bridgeSize; ++i) {
        if (target[targetLoc + 1] == bridge[(1 ^ type)][i] ) {
            res += dfs(i, 1^type, targetLoc+1);
        }
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> (target + 1);
    cin >> (bridge[0] + 1);
    cin >> (bridge[1] + 1);
    memset(dp, -1, sizeof(dp));
    for (int i = 1 ; target[i] != '\0'; ++i) targetSize++;
    for (int i = 1 ; bridge[0][i] != '\0'; ++i) bridgeSize++;


    cout << (dfs(0,0,0) + dfs(0,1,0));

    return 0;
}