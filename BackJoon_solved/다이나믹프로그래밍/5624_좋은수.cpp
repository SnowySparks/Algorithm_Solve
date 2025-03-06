#include <iostream>
using namespace std;
const int OFFSET = 2e5;
int n;
int a[5000];
bool dp[2*OFFSET + 2];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[ a[i] - a[j] + OFFSET]) {
                ++cnt; break;
            }
        }
        for (int j = 0; j <= i; ++j) {
            dp[ a[i] + a[j] + OFFSET ] = true;
        }
    }
    cout << cnt;
    return 0;
}