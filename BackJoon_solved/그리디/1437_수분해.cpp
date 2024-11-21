#include <iostream>
using namespace std;
const int mod = 10007;

int pow(int x, int r) {
    int res = 1;
    int p = x;
    while (r)
    {
        if (r & 1) res = res * p % mod;
        p = p*p%mod;
        r >> 1;
    }
    return res;
    
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //그리디 : 가능하면 2 혹은 3 을 많이 곱하는 것이 이득, 가능하면 3을 우선적으로
    int n; cin >> n;
    int r = 1;
    if (n <= 4) cout << n;
    else {
        while (n >= 5)
        {
            n-=3;
            r*=3;
            r%=mod;
        }
        if (n == 4) r = r*4%mod;
        else if (n == 3) r = r*3%mod;
        else r = r*n%mod;
        cout << r;
    }
    return 0;
}

//https://oeis.org/A000792
//https://www.geeksforgeeks.org/breaking-integer-to-get-maximum-product/

//증명, x의 수들로 나눈다고 두면 답은 x^(n/x) -> 미분시 nx^(n/x-2)*(1-ln(x)) x == e 에서 최대값.
//그러나 정수만 곱해야 하니, 가능한 3을 먼저 곱하고 나머지 2를 곱하는 식이어야 함