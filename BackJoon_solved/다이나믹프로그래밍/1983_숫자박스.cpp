#include <iostream>
#include <vector>
#include <algorithm>
#define f(a,b,c) for(int a=b;a<c;a++)
#define fr(a,b,c,r) for(int a=b;a<c;a+=r)
using namespace std;
const int mv = -1 * 401 * 101;
int N;
int dt[2][401];
int dp[401][401][401];
int cnt[2];
/*
int dfs(int loc, int fir, int sec) {
    if (fir == cnt[0] || sec == cnt[1]) return 0;
    int &ret = dp[loc][fir][sec];
    if (ret!=mv) return ret;
    ret = mv;
    if (cnt[0] - fir < N - loc) ret = max(ret,dfs(loc+1,fir,sec+1));
    if (cnt[1] - sec < N - loc) ret = max(ret,dfs(loc+1,fir+1,sec));
    return ret =max(ret, dfs(loc+1,fir+1,sec+1) + dt[0][fir]*dt[1][sec]);
}
*/
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    
    f(i,0,2) f(j,0,N) {
        cin >> dt[i][cnt[i]];
        if (dt[i][cnt[i]]) cnt[i]++;}
    
    f(i,0,N+1) f(k,0,N+1) fill(dp[i][k],dp[i][k]+N+1,mv);
   
   f(i,0,N) f(j,0,N) f(k,0,N) { // up, down, loc
    
   }
    return 0;
}