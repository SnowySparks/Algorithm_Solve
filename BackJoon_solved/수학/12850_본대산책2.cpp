#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;
const ll MOD = 1e9 + 7;

// A * B
matrix operator*(const matrix &A, const matrix &B) {
    int row = A.size();
    int col = B[0].size();
    int mid = A[0].size();
    matrix res = vector<vector<ll>>(row, vector<ll>(col, 0));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            for (int k = 0; k < mid; ++k) {
                res[i][j] += (A[i][k] * B[k][j] % MOD);
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    // 순서대로 : 형남, 학생, 환경, 진리 ,신앙, 미래, 전신, 정보
    matrix A = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0 ,0, 0, 0},
        {1, 0, 0, 1, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
    };
    matrix B = {
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
    };

    while (n>0)
    {
        if (n & 1) {
            B = B * A;
        }
        A = A*A;
        n>>=1;
    }
    cout << B[7][7];
    return 0;
}