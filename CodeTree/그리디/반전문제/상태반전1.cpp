#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    bool flag = false;
    int ans = 0;
    for (int i = 0; i <n; ++i ) {
        if (a[i] != b[i]) {
            if (!flag) {
                flag = true;
                ++ans;
            }
        }
        else {
            flag = false;
        }
    }
    cout << ans;
    return 0;
}