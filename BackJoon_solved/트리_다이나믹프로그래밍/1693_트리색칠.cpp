#include <iostream>
#include <vector>
#include <cstring>
#define F(a,b) for (int i = a ; i <= b ; i++)
using namespace std;
const int M = 1E5+1;
long long dp[M][19];
bool v[M];
int N;
vector<int> gh[M];
long long dfs(int cur, int color) {
    long long &res = dp[cur][color];
    if (res != -1) return res;
    v[cur] = true;
    long long p = 0;
    for (auto e : gh[cur]) {
        if (v[e]) continue;
        long long t = 1E15;
        F(1,18) {
            if (color == i) continue;
            t = min(t, dfs(e, i));
        }
        p += t;
    }
    v[cur] = false;
    return res = p + color;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int a, b;
    F(1,N-1) {
        cin >> a >> b;
        gh[a].push_back(b);
        gh[b].push_back(a); }
    memset(dp, -1 , sizeof(dp));
    long long answer = 1E15;
    for (int i = 1 ; i <19; i++) {
        answer = min(answer, dfs(1,i));
    }
    cout << answer; return 0;
}