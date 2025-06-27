#include <iostream>
using namespace std;
const int inf = 1e9 + 7;
int N, T, M, S, E;
int dist[1001][10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> T >> M >> S >> E;
	for (int i = 0; i < N; i++) dist[0][i] = inf;
	dist[0][S] = 0;
	for(int t = 0; t < T; t++) {
		for (int i = 0; i < N; i++) dist[t + 1][i] = dist[t][i];
		for (int i = 0; i < M; i++) {
			int u, v, w; cin >> u >> v >> w;
			dist[t + 1][v] = min(dist[t + 1][v], dist[t][u] + w);
			dist[t + 1][u] = min(dist[t + 1][u], dist[t][v] + w);
		}
	}

    cout << (dist[T][E] < inf ? dist[T][E] : -1);
}