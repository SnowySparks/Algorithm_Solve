#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum[301][301];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;
    int temp = 0;

    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1 ; j <= M ; j++) {
            cin >> temp;
            if (i == 1 && j == 1) sum[i][j] = temp;
            else sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + temp;
        }
    }

    cin >> temp;
    int r1,c1,r2,c2;
    while (temp--) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << (sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1]) <<'\n';
    }
    return 0;

}