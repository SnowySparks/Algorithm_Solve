#include <iostream>
#include <algorithm>
#include <cstring>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
int n, dp[1000], arr[1000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    f(i, 1, n) {
        f(j, 0, i) { //j 위치가 시작에서 도달 가능한 곳이면서 arr[j] + j >= i가 성립할 때만 적용
            if (arr[j] + j >= i && dp[j]!= -1) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp, dp+n);
    return 0;
}