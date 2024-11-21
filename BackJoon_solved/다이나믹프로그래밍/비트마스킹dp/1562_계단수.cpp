#include <iostream>
#include <algorithm>
#include <cstring>
#define f(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll = long long;
const int md = 1E9;
int dp[101][10][1<<10];
int N;

int dfs(int len, int ln, int bit) {
    if (dp[len][ln][bit]!=-1) return dp[len][ln][bit];
    if (len == N) return bit == 1023 ? 1 : 0;
    int ret = 0;
    if (ln < 9) ret+= dfs(len+1,ln+1,bit|(1<<(ln+1)))%md;
    if (ln > 0) ret+= dfs(len+1,ln-1,bit|(1<<(ln-1)))%md;
    return dp[len][ln][bit] = (ret%md);
}



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    memset(dp,-1,sizeof(dp));
    int result = 0;
    f(i,1,10) {
        result += dfs(1,i,1<<(i));
        result%= md;
    }
    cout << result; return 0;
}