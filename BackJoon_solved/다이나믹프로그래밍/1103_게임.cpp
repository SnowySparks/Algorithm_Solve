#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
string dt[50];
int dp[50][50];
bool visited[50][50];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int dfs(int r, int c) {
    if (r < 0 || c < 0 || r >= N || c >= M || dt[r][c] == 'H') return 0;
    if (visited[r][c]) {cout << -1 ; exit(0);}
    int &ret = dp[r][c];
    if (ret != -1) return ret;

    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + (dt[r][c] - '0')*dr[i];
        int nc = c + (dt[r][c] - '0')*dc[i];

        ret = max(ret, dfs(nr,nc)+1);
    }
    visited[r][c] = false;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> dt[i];
    }
    for (int i = 0; i < N; i++) fill(dp[i], dp[i]+M,-1);
    cout << dfs(0,0);
    return 0;
}

