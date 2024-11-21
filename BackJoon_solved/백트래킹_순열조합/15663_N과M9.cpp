#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, arr[8], res[8]; 
bool chk[8] = { false }; 

void func(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << res[i] <<' ';
		cout << '\n';
		return;
	}
	int ln = 0;
	for (int i = 0; i < n; i++) {
		if (!chk[i] && arr[i] != ln) {
			res[cnt] = arr[i];
			ln = res[cnt];
			chk[i] = true;
			func(cnt + 1);
			chk[i] = false;
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	func(0);
}