#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define f(a,b,c) for (int a=b ;a<=c;a++)
using namespace std;
using ll = long long;
int N, M, C;

int W[17][17];
int A[1001], B[1001];
ll dp[1001][1001];

int dfs(int a, int b) {
    if (a > N || b > M) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    ll &r = dp[a][b];
    r = max( W[A[a]][B[b]] + dfs(a+1,b+1) , max( dfs(a+1,b) , dfs(a,b+1)));
    return r;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> C;
    f(i,1,C) f(k, 1, C) cin >> W[i][k];
    f(i,1,N) cin >> A[i];
    f(i,1,M) cin >> B[i];
    memset(dp, -1, sizeof(dp));
    cout << dfs(1,1);
}