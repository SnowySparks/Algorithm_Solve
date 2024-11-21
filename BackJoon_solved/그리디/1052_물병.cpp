#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    if (n <= k) {
        cout << 0;
        return 0;
    }
    vector<int> loc;
    int tmp = 1;
    for (int i = 0; i < n; ++i) {
        if (tmp & n) loc.push_back(i);
        tmp<<=1;
    }
    int p = loc.size();
    if(p <= k) {
        cout << 0;
        return 0;
    }

    for (int i = p-1; i >= p - k; --i) n -= (1<<loc[i]);

    int ans = (1 << loc[p - k]) - n;
    cout << ans;

    return 0;
}

// 원리 : 그룹핑은 2^n 크기 만큼 할 수 있음.
// 따라서 2진수로 바꿀 때 1의 개수가 k보다 작거나 같은 경우 답은 0
// 초과할 경우 k-1 배정은 가장 큰 2^n들에 배정하고 나머지 것에 대해 가능한 최소로 더하면 됨