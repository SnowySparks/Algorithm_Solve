#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define F(a,b) for (int i = a ; i <= b ; i++)
const int MAX = 5E5+1;
int dp[MAX][3];
bool v[MAX];
int c[MAX];
vector<int> gh[MAX];
void dfs(int root) {
    v[root] = true;
    for (auto e : gh[root]) {
        if (v[e]) continue;
        dfs(e);
        dp[root][0] += max(dp[e][1], dp[e][2]);
        dp[root][1] += max(dp[e][0], dp[e][2]);
        dp[root][2] += max(dp[e][1], dp[e][0]);
    }
}
void check(int root, int col) {
    v[root] = true;
    int mloc = -1;
    int x = -1;
    F(0,2) {
        if (i == col) continue;
        if ( x < dp[root][i] ) {
            mloc = i; x = dp[root][i];
        }
    }
    c[root] = mloc;
    for (auto e : gh[root]) {
        if (v[e]) continue;
        check(e,mloc);
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int a, b;
    F(1,N-1) {
        cin >> a >> b;
        gh[a].push_back(b);
        gh[b].push_back(a); }
    F(1,N) cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    dfs(1);
    cout << *max_element(dp[1], dp[1]+3) << '\n';
    memset(v, false, sizeof(v));
    F(1,N) c[i] = -1;
    check(1,-1);
    F(1,N) {
        if (c[i] == 0) cout << 'R';
        else if (c[i] == 1) cout << 'G';
        else cout << 'B';
    }
    return 0;
}