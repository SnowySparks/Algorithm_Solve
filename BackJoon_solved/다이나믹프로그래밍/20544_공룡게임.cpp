#include<iostream>
#include<algorithm>
#include<cstring>
using ll = long long;
using namespace std;
ll dp[1001][3][3][2];
ll mod = 1e9 + 7;
int n;

ll dfs(int idx, int nowHeight, bool flag, int beforeHeight) {

	ll &res = dp[idx][nowHeight][beforeHeight][flag];

	if (idx == n) {
		if (flag)
			return res = 1;
		else
			return res = 0;
	}	
	if (res != -1)
		return res;
	res = 0;

	if (nowHeight == 0) {
		res += dfs(idx + 1, 0, flag, nowHeight) % mod;
		res += dfs(idx + 1, 1, flag, nowHeight) % mod;
		res += dfs(idx + 1, 2, true, nowHeight) % mod;
	}
	else if (nowHeight == 1) {
		if (beforeHeight == 0) {
			res += dfs(idx + 1, 0, flag, nowHeight) % mod;
			res += dfs(idx + 1, 1, flag, nowHeight) % mod;
			res += dfs(idx + 1, 2, true, nowHeight) % mod;
		}
		else {
			res += dfs(idx + 1, 0, flag, nowHeight) % mod;
		}
	}
	else if(nowHeight == 2){
		if (beforeHeight == 0) {
			res += dfs(idx + 1, 0, flag, nowHeight) % mod;
			res += dfs(idx + 1, 1, flag, nowHeight) % mod;
		}
		else {
			res += dfs(idx + 1, 0, flag, nowHeight) % mod;
		}
	}
	res %= mod;
    return res;
}

int main() {

	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	cin >> n;
    memset(dp,-1,sizeof(dp));
	cout << dfs(1, 0, false, 0);
    return 0;
}