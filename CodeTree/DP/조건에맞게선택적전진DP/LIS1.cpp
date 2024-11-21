#include <iostream>
#include <algorithm>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
int n, dp[1000], arr[1000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) cin >> arr[i];
    fill(dp, dp+n, 1);
    f(i, 1, n) {
        f(j, 0, i) {
            if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp, dp+n);
    return 0;
}