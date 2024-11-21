//https://www.codetree.ai/missions/8/problems/three-five-moo/description
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n; cin >> n;

    long long l = 1, r = 1e18;

    long long ans = 0;

    while(l <= r) {
        long long mid = (l + r) >> 1;
        long long cnt = mid - (mid/3) - (mid/5) + (mid/15);

        if (cnt >= n) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;

    return 0;
}