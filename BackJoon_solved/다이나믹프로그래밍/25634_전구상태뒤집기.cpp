#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;
int light[N];
int isOn[N];
int dp[N];
int n;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int totalLight = 0;
    for (int i = 1; i <= n; ++i) cin >> light[i];
    
    for (int i = 1; i <= n; ++i) {
        cin >> isOn[i];
        if (isOn[i]) totalLight+=light[i];
    }

    // dp연산
    // 뒤집었을때의 연속합 최대값
    for (int i = 1; i <= n; ++i) {
        int changeLight = (isOn[i] == 1 ? -light[i] : light[i]);
        dp[i] = max(dp[i-1] + changeLight, changeLight );
    }

    cout << totalLight + (*max_element(dp+1, dp+1+n));
    return 0;
}