#include <iostream>
#include <algorithm>
#include <cstring>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;

int n, m;
int dp[101][10001]; // 1~i번째, 최대 무게가 w일때 최대가치

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int w, v;
    f(i, 1, n+1) {
        cin >> w >> v;
        f(j, 1, m+1) {
            if (j >= w) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout <<dp[n][m];
    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <climits>

// #define MAX_N 100
// #define MAX_M 10000

// using namespace std;

// // dp[j] : 지금까지 고른 보석 무게의 합이 j였을 때 
// //         얻을 수 있는 최대 가치
// int dp[MAX_M + 1];

// int n, m;

// int weight[MAX_N + 1], value[MAX_N + 1];

// void Initialize() {
//     // 최대를 구하는 문제이므로, 
//     // 초기에는 전부 INT_MIN을 넣어줍니다.
//     for(int j = 0; j <= m; j++)
//             dp[j] = INT_MIN;
    
//     // 초기 조건으로
//     // 아직 아무런 보석도 고려해보지 않은 상태를 정의합니다.
//     // 따라서 지금까지 0번째 보석까지 고려해봤고,
//     // 지금까지 고른 보석 무게의 합이 0이었을 때
//     // 가치를 0만큼 얻었으므로
//     // dp[0] = 0을 초기 조건으로 설정합니다.
//     dp[0] = 0;
// }

// int main() {
//     cin >> n >> m;

//     for(int i = 1; i <= n; i++)
//         cin >> weight[i] >> value[i];

//     Initialize();

//     // 지금까지 i번째 보석까지 고려해봤고,
//     // 지금까지 고른 보석 무게의 합이 j였을 때 
//     // 얻을 수 있는 최대 가치를 계산합니다.
//     for(int i = 1; i <= n; i++){
//         // 같은 보석을 중복하여 사용할 수 없기 때문에
//         // 반복문을 거꾸로 돌려 보석을 중복하여 사용하는 것을 방지합니다.
//         for(int j = m; j >= weight[i]; j--)
//             dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
//     }

//     // n개의 보석까지 전부 고려해봤을 때
//     // 무게의 합이 m을 넘지 않는 경우를 전부 조사하여
//     // 그 중 최댓값을 선택합니다.
//     int ans = 0;

//     for(int j = 0; j <= m; j++)
//         ans = max(ans, dp[j]);

//     cout << ans;
// }