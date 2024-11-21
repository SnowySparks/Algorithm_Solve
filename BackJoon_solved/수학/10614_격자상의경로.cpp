#include <iostream>
using namespace std;
using ll = long long;
int n, m, k;

ll path(int a, int b) {
    int mo = a + b;
    long long ret = 1;
    int j = 1;
    for (int i = a + 1; i <= mo; i++) {
        ret *= i;
        while (j <= b && (ret % j == 0)) {
            ret /= j++;
        }
    }
    return ret == 0 ? 1 : ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    k = k == 0 ? 0 : k - 1;
    int x1 = k / m, y1 = k % m;
    int x2 = n - 1 - x1, y2 = m - 1 - y1;
    cout << path(x1, y1) * path(x2, y2);
    return 0;
}