#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define f(a,b,c) for(int a = b; a < c; a++)
using namespace std;
int N, P;
int dt[16][16];
int dp[1<<16];
string s;

int count1(int state) {
    int r = 0;
    while(state) {
        r += (state & 1);
        state = state>> 1; }
    return r; 
}

int dfs(int state) {
    if (count1(state) >= P) return 0;
    int &ret = dp[state];
    if (ret != -1) return ret;
    ret = 1E8;
    f(i,0,N) {
        if ((state & (1<<i))) {
            f(j, 0, N) {
                if (!(state & (1<<j))) ret = min(ret, dfs(state | (1<<j)) + dt[i][j]);
            }
        }
    }
    return ret; }

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    f(i,0,N) {
        f(k, 0, N) cin >> dt[i][k]; }
    cin >> s; cin >> P;
    int state = 0;
    f(i, 0, N) if (s[i] == 'Y') state |= (1 << i);
    memset(dp, -1, sizeof(dp));
    if (P == 0) {cout << 0; return 0;}
    else if (dfs(state) >= 1E8 || dfs(state) < 0) cout << -1;
    else cout << dfs(state);
    return 0;
}