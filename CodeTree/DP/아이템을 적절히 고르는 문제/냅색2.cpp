#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
// 냅색문제랑 차이점, 갯수 제한이 없음 각각 물품에 대해서
// 1차원적으로 해결 가능. (1개란 제한이 없으니 계속 dp값에 누적된 값을 이용하는 것과 같음)
int n, m;
int dp[10001]; // 1~i번째, 최대 무게가 w일때 최대가치

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int w, v;
    int a,b;
    f(i, 0, n) {
        cin >> w >> v;
        f(j, w, m+1) dp[j] = max(dp[j], dp[j-w] + v);
    }
    cout <<dp[m];
    return 0;
}