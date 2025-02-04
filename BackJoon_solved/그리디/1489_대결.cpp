#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a[50], b[50];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a, a+n); //오름차순
    sort(b, b+n,greater<int>()); // 내림차순
    int ans = 0;
    for (int aIdx = 0; aIdx < n; ++aIdx) {

        // a[aIdx] > b[bIdx] 있는가? - aIdx가 이길수 있는 가장 큰 b를 먼저 찾아없애기
        for (int bIdx = 0; bIdx < n; ++bIdx) {
            if (b[bIdx] == 0) continue;
            if (a[aIdx] > b[bIdx]) {
                ans+= 2;
                b[bIdx] = 0;
                a[aIdx] = 0;
                break;
            }
        }
    }

    for (int aIdx = 0; aIdx < n; ++aIdx) {
        if (a[aIdx] == 0) continue;
        for (int bIdx = 0; bIdx < n; ++bIdx) {
            if (b[bIdx] == 0) continue;
            if (a[aIdx] == b[bIdx]) {
                ans++;
                b[bIdx] = 0;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}