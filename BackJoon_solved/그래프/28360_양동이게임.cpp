#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define f(a,b,c) for (int a = b; a < c; a++)
using namespace std;
using d = long double;

vector<int> gh[51];
int n, m;
d dp[51];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout<<fixed;
    cout.precision(7);
    cin >> n >> m;
    f(i,0,m) {
        int s, e;
        cin >> s >> e;
        gh[s].push_back(e);
    }
    dp[1] = 100.0;

    f(i,1,n+1) {
        if (gh[i].empty()) continue;
        for(int nxt : gh[i]) {
            dp[nxt]+= dp[i]/gh[i].size();
        }
        dp[i]=0;
    }
    cout << *max_element(dp+1,dp+1+n);
    return 0;
}