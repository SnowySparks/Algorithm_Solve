#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int tb[100001];
bool visited[100001];
vector <vector<int>> v(100001);

void dfs(int k) {
	visited[k] = true;
	for (auto e : v[k]) {
		if (!visited[e]) {
			tb[e] = k;
			dfs(e);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n; cin >> n;
	int a,b;

	for (int i = 1 ; i <= n-1 ; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i =2; i<= n ; i++) {
		cout << tb[i]<<'\n';
	}

	return 0;
}
