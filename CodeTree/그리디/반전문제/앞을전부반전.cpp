#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
int arr1[1000], arr2[1000];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s;

    cin >> s;
    f(i, 0, n) arr1[i] = (s[i] == 'G' ? 1 : 0);

    cin >> s;
    f(i, 0, n) arr2[i] = (s[i] == 'G' ? 1 : 0);

    int ans = 0;
    for (int i = n-1; i >= 0; --i) {
        if (arr2[i]^arr1[i]) {
            f(j, 0, i+1) {
                arr1[j]^=1;
            }
            ++ans;
        }
    }
    cout << ans;
    return 0;
}

// 이렇듯 선택에 의해 앞에 있는 모든 값들이 반전되는 문제의 경우에는,
// 뒤에서 부터 순차적으로 진행하며 꼭 눌려야만 하는 위치를 판단하는 식으로 문제를 해결할 수 있습니다.
// 뒤에서 부터 판단시 "가장 뒤" 에 영향 주는 건 오로지 "가장 뒤" 밖에 없다