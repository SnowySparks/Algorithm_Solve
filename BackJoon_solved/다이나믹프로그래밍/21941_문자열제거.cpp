#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f(a,b,c) for(int a=b; a<c;a++)

int m;
int dp[1002];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s; s = "."+s;
    cin >> m;
    vector< pair<string, int> > v(m);
    f(i,0,m) cin >> v[i].first >> v[i].second;
    f(i,1,s.size()+1) {
        f(j, 0, m) {
            int sz = v[j].first.size();
            if (sz <= i && s.substr(i-sz,sz) == v[j].first) dp[i] = max(dp[i],dp[i-sz]+v[j].second);
        }
        dp[i] = max(dp[i-1]+1, dp[i]);
    }
    cout << dp[s.size()]-1;
    
}
