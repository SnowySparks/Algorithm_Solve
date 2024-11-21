#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long dp[61][61]; // 남는 한알 개수 , 남는 반알 개수
int N;

long long dfs(int w, int h) {
    if ( w == 0 ) return 1; 
    if (dp[w][h] != 0) return dp[w][h];

    if (h > 0) dp[w][h] += dfs(w-1,h+1) + dfs(w,h-1);
    else dp[w][h] += dfs(w-1,h+1);
    return dp[w][h];
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int inp;
    while(true) {
        cin >> inp;
        if (inp == 0) break;
        cout << dfs(inp,0) << '\n';
        memset(dp,0,sizeof(dp));
    }
}