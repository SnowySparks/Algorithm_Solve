#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
const int inf = 1e9 + 7;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ans = -inf;
    int total = 0;
    int tmp;
    f(i, 0, n) {
        cin >> tmp;
        if (i==0) {
            total = tmp;
            ans = total;
        }
        else {
            total += tmp;
            if (total < 0) total = tmp;
            ans = max(ans, total);
        }
    }
    cout << ans;
    return 0;
}

// 왼쪽에서부터 순서대로 숫자들을 보며 구간을 확장시키다가, 
// 합이 0보다 작아지는 순간 구간 확장을 멈추고 그 다음 원소부터 다시 구간을 만들어나가는 그리디가 가능