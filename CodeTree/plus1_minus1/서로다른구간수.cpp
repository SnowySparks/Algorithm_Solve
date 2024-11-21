#include <iostream>
#include <cstring>
#include <algorithm>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
const int max_cord = 2e5;
int n;
int arr[max_cord+2];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int fr, to;
    int max_val = -1;
    f(i, 1, n+1) {
        cin >> fr >> to;
        arr[fr]++;
        arr[to+1]--;
        max_val = max(max_val, to);
    }
    int ans = -1;
    f(i, 1, max_val+1) {
        arr[i] += arr[i-1];
        ans = max(ans, arr[i]);
    }
    cout << ans;
    return 0;
}