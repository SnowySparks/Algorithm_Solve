#include <iostream>
#include <cstring>
#include <queue>
#define f(a, b, c) for(int a = b; a < c; ++a)
using namespace std;
const int maxn = 1e5+1;
int n;
int arr[maxn], l[maxn], r[maxn]; 

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 1, n+1) cin >> arr[i];
    f(i, 1, n+1) l[i] = max(l[i-1], arr[i]);
    for(int i = n; i >= 1; --i) r[i] = max(r[i-1], arr[i]);
    int ans = -1;
    f(i, 2, n-2) {
        ans = max(ans, l[i-2] + arr[i] + r[i+1]);
    }
    cout << ans;
    return 0;
}