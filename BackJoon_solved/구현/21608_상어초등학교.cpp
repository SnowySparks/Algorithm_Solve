#include <iostream>
using namespace std;

int N;
int student;
int arr[401][4];
int map[20][20] = {};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int countLike(int y, int x, int s) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

		for (int j = 0; j < 4; j++) {
			if (map[ny][nx] == arr[s][j]) {
				ret++;
				break;
			}
		}
	}

	return ret;
}

int countEmpty(int y, int x) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (map[ny][nx] == 0) ret++;
	}

	return ret;
}

void find(int s) {
	int like = 0;
	int empty = -1;
	int fi;
	int fj;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) continue;

			int cl = countLike(i, j, s);
			int ce = countEmpty(i, j);
			if (like < cl) {
				like = cl;
				empty = ce;
				fi = i;
				fj = j;
			}
			else if (like == cl) {
				if (empty < ce) {
					empty = ce;
					fi = i;
					fj = j;
				}
			}
		}
	}

	map[fi][fj] = s;
}

int calculate() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int s = map[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
								
				for (int l = 0; l < 4; l++) {
					if (map[ny][nx] == arr[s][l]) {
						cnt++;
						break;
					}
				}
			}
			if (cnt == 2) ret += 10;
			else if (cnt == 3) ret += 100;
			else if (cnt == 4)ret += 1000;
			else ret += cnt;
		}
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	student = N * N;

	int s;
	for (int i = 1; i <= student; i++) {
		cin >> s;

		for (int j = 0; j < 4; j++) {
			cin >> arr[s][j];

		}
		find(s);
	}

	cout << calculate();

	return 0;
}