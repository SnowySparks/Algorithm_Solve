#include <iostream>
#include <algorithm>
using namespace std;
double dp[10001];
double arr[10001];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	double ans = 0.0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(arr[i], dp[i - 1] * arr[i]);
		ans = max(dp[i], ans);
	}
	printf("%.3lf", ans);
}