#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int sums[3][1001][1001];
string in;
char inp[1001][1001];
int N, M;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    int T; cin >> T;
    for (int i = 1; i <= N ; i++) {
        cin >> in;
        for (int k = 1; k <= M ; k++) {
            inp[i][k] = in[k-1];
        }
    }
    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j <= M ; j++) {
            for (int k = 0 ; k < 3 ; k++) {
                sums[k][i][j] = sums[k][i-1][j]+sums[k][i][j-1]-sums[k][i-1][j-1];
            }
            if (inp[i][j] == 'J') sums[0][i][j]++;
            if (inp[i][j] == 'O') sums[1][i][j]++;
            if (inp[i][j] == 'I') sums[2][i][j]++;
        }
    }

    while (T--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        for (int i = 0 ; i < 3 ; i++) {
            cout << sums[i][r2][c2] - sums[i][r2][c1-1] - sums[i][r1-1][c2] + sums[i][r1-1][c1-1] << ' ';
        } cout << '\n';
    }
    return 0;
}