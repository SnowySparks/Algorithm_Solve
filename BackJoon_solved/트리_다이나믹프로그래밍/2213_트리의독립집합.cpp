#include <iostream>
#include <vector>
using namespace std;
#define f(a,b,c) for(int a=b; a<c;a++)
const int inf = 1e5+1;

bool v[inf];
int dp[inf][2];
bool sel[inf];
int n;

vector<int> gh[inf];
vector<int> ans;
void dfs(int loc) {
    v[loc] = true;
    for (int e : gh[loc] ) {
        if (v[e]) continue;
        dfs(e);
        dp[loc][0] += max(dp[e][0],dp[e][1]);
        dp[loc][1] += dp[e][0];
    }
}

void bdfs(int node, int p_sel) {
    v[node] = true;
    if (p_sel!=1 && dp[node][1] > dp[node][0] ) sel[node] = true;
    for (int e : gh[node]) {
        if (v[e]) continue;
        bdfs(e, sel[node] ? 1 : 0);
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i,1,n+1) cin >> dp[i][1];
    f(i,0,n-1) {
        int a, b; cin >> a >> b;
        gh[a].push_back(b);
        gh[b].push_back(a);
    }
    dfs(1);
    fill(v,v+n+1,false);
    cout << max(dp[1][0],dp[1][1]) <<'\n';
    bdfs(1,-1);
    f(i,1,n+1) {
        if (sel[i]) cout << i <<' ';
    }
    return 0;
}
