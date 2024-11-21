#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
const int inf = 1e9+7;
int n, arr[100], tmp[100];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) cin >> arr[i];

    // 첫번째 버튼 안눌렀을 경우
    int ans2 = 0;
    memcpy(tmp, arr, sizeof(int)*n);
    for (int i = 1; i <n; ++i) {
        if (tmp[i-1]!=1) {
            tmp[i-1]^=1;
            tmp[i]^=1;
            if (i < n-1) tmp[i+1]^=1;
            ++ans2;
        }
        else continue;
    }

    cout << (tmp[n-1] == 0 ? -1 : ans2);

    // 첫번째 버튼눌렀는 경우 & 안눌렀는 경우를 나누면
    // 그 이후를 살펴볼 때 i-1번째 에 영향을 줄 수 있는 것은 오로지 i번째 버튼밖에 없다 라는 것을 이용
    return 0;
}