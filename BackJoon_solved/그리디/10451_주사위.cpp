#include <iostream>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
const int maxn = 1e6+1;
const int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5;
int n;
long long arr[6];
long long ans = 0;

const int case_2d[12][2] = {
    {a, b},
    {a, c},
    {a, d},
    {a, e},
    {f, b},
    {f, c},
    {f, d},
    {f, e},
    {b, c},
    {c, d},
    {d, e},
    {e, c}
};

const int case_3d[12][3] = {
    {a, e, d},
    {a, d, b},
    {a, b, c},
    {a, c, e},
    {f, e, d},
    {f, d, b},
    {f, b, c},
    {f, c, e},
    {a, f, b},
    {a, f, c},
    {a, f, d},
    {a, f, e}
};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, 6) cin >> arr[i];
    
    if (n == 1) {
        f(i, 0, 6) ans += arr[i];
        ans -= *max_element(arr, arr+6);
        cout << ans;
        return 0;
    }

    

    return 0;
}