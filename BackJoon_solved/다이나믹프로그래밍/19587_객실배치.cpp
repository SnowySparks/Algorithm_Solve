#include <iostream>
#include <vector>
#include <cstring>
using ll = long long;
#define matrix vector<vector<ll>>
const ll MOD = 1e9 + 7;
using namespace std;

// 행렬곱 연산
matrix operator*(const matrix &a, const matrix &b) {
    int rows = a.size();
    int cols = b[0].size();
    int common_dim = a[0].size();
    matrix result(rows, vector<ll>(cols, 0));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            for (size_t k = 0; k < common_dim; ++k) {
                result[i][j] += (a[i][k] * b[k][j])%MOD;
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}


matrix A = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
matrix res = {{1, 1, 1}, {1, 0, 1}, {1, 1, 0}};
matrix x = {{1},{1},{1}};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll N; cin >> N;
    N--;

    // A*(res^(n-1))
    while (N)
    {
        if (N&1) {
            A = A*res;
        }
        res = res * res;
        N>>=1;
    }
    matrix b = A * x;
    ll ans = b[0][0] + b[1][0] + b[2][0];
    cout << ans%MOD;
    return 0;
}
