#include <iostream>
#include <cstring>
#include <algorithm>
#define f(a, b, c) for (int a=b;a<c;++a)
using namespace std;
const int inf = 1e9+7;
int n, m, man[1003], woman[1003], dp[1003][1003];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    // dp[i][j], 남자 i, 여자 j 까지 보았을때 커플링 값 최소
    // 단 항상 min(i, j)의 커플이 항상 존재해야함
    f(i, 1, n+1) cin >> man[i];
    f(i, 1, m+1) cin >> woman[i];

    sort(man, man+n+1);
    sort(woman, woman+m+1);

    // f(i, 0, n+1) f(j, 0, m+1) dp[i][j] = inf;
    // 이거 하니까 문제가 발생했음
    // dp[0][1] 같은 접근에서 ... dp[1][2] 에 대한 계산을 해야 할 때..


    dp[0][0] = 0;

    f(i, 1, n+1) { 
        f(j, 1, m+1) {
            dp[i][j] =  dp[i-1][j-1] + abs(man[i] - woman[j]); // 일단 (i, j) 남여 짝 짓는 경우 계산
            if (i < j) { //남자는 무조건 여자는 선택적
                dp[i][j] = min(dp[i][j], dp[i][j-1]); // 
            }
            else if (j < i) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
            // i == j 인 경우, 무조건 짝을 일단 많이 맞추어야 하니 이 부분은 소거
            // 또 같은 경우, 그리디적으로 무조건 성립
        }
    }
    cout << dp[n][m];
    
    // f(i, 1, n+1) {
    //     f(j, 1, m+1) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }


    return 0;   
}

// 원리
// 남여 수 가 "같으면" 그리디적 접근이 무조건 유효 (최소값끼리 빼기)
// 그러나 다를 경우, 먼저 짝짓는 것이 오히려 유효하지 않을 수 가 있음
// 이때 많은 쪽은 "짝을 맺거나 포기하거나" 옵션이 있음 - 이를 항상 갱신함으로써 dp식 보장
// 