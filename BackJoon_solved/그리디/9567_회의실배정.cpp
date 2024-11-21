#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a.begin(), a.end());
	int t = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (t <= a[i].second) {
			t = a[i].first;
			ans++;
		}
	}
	cout << ans;
    return 0;

}
