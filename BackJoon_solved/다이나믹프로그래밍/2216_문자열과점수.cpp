#include <iostream>
#include <cstring>
using namespace std;
const int INF = 1e9 + 7;
string X, Y;
int dp[3001][3001];
int a, b, c;

int dfs(int i, int j) {
    if (i == X.size() && j == Y.size()) return 0;
    if (i == X.size()) return (dfs(i,j+1) + b);
    if (j == Y.size()) return (dfs(i+1,j) + b);

    int &res = dp[i][j];
    if (res != -INF) return res;
    res = max( dfs(i,j+1), dfs(i+1,j) ) + b;
    if (X[i] == Y[j]) res = max(res, a + dfs(i+1,j+1));
    else res = max(res, c + dfs(i+1,j+1));
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    cin >> X >> Y;
    for (int i = 0; i < 3001; ++i) {
        for (int j = 0; j < 3001; ++j) {
            dp[i][j] = -INF;
        }
    }
    cout << dfs(0, 0);
    return 0;
}