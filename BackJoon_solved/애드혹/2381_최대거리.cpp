#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int inf = 1e9;
vector<pii> arr;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pii> arr(n);

    int xpy, xmy; // (x+y)의 최대 - 최소 값, (x-y)의 최대 - 최소 값
    for (int i =0; i<n;++i) {
        cin >> arr[i].first >> arr[i].second;
    }

    int max_v = -inf, min_v = inf;

    for (auto &[a, b] : arr) {
        max_v = max(max_v, a+b);
        min_v = min(min_v, a+b);
    }
    xpy = max_v - min_v;

    max_v = -inf;
    min_v = inf;

    for (auto &[a, b] : arr) {
        max_v = max(max_v, a-b);
        min_v = min(min_v, a-b);
    }

    xmy = max_v - min_v;

    cout << max(xpy, xmy);

    return 0;
}

// 거리 |a-c| + |b - d|
// 연산할때 무조건 x오름차순 기준으로 두면 b, d 관계에서 다음과 같은 것이 성립함

// if (b < d) : dist = c - a + d - b = (c + d) - (a + b)
// else dist = c - a + b - d = (c - d) - (a - b)

// 따라서 (x+y)결과의 최대 - 최소 값과   (x-y)결과의 최대, 최소 값 둘 중 최대값이 답