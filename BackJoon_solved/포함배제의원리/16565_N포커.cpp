#include <iostream>
#include <vector>
using namespace std;
int dv = 10007;
int cm[53][53];
int n;
bool cal = false;

int comb(int n, int r) {
    if (!cal) {
    for (int i = 0; i <= 52 ; i++) {
        for (int j = 0 ; j <= i; j++) {
            if (j == 0 || j == i) cm[i][j] = 1;
            else if (j == i) cm[i][j] = i;
            else cm[i][j] = (cm[i-1][j-1] + cm[i-1][j]) % dv;
        }
    }
    cal = true;
    }
    return cm[n][r];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int ans = 0;
    // 1개이상 포커 - 2개이상 포커 + 3개이상 포커 - ... -> 포함 배제
    for (int i = 1 ; i <= 13 && n >= 4*i ; i++) {
        int v = comb(13,i) * comb(52-4*i,n-4*i) % dv;
        if (i%2) ans += v;
        else ans = (ans - v + dv)%dv;
        ans %= dv;
    }
    cout << ans;
    return 0;
}