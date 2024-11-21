#include <iostream>
#define f(a, b, c) for (int a=b;a<c;++a)
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
ll dp[20];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <=n; ++i) {
        for (int j = i-1; j >= 0; --j) dp[i] += dp[j]*dp[i-j-1];
    }
    cout << dp[n];
    return 0;
}

//카탈란 수
// 혹은 트리의 특성을 이용
// 루트를 제외하면 n-1개 노드가 남았는데, 왼쪽 subtree, 혹은 오른쪽 subtree임
// 따라서 