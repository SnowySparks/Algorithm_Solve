#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1001][1001]; //dp[i][j] 첫번쨰 문자열이 i 번째까지 부분이 두번째 문자열 j번째 까지 부분으로 바꾸기 위해서
// 편집 거리 알고리즘

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string a = ".", b =".", temp;
    cin >> temp; a.append(temp);
    cin >> temp; b.append(temp);

    int a_length = a.size() - 1, b_length = b.length() - 1;

    // 초기 셋팅
    for (int i = 1; i <= a_length; ++i)  dp[i][0] = i;
    for (int i = 1; i <= b_length; ++i)  dp[0][i] = i;

    for (int i = 1; i <= a_length; ++i) {
        for (int j = 1; j <= b_length; ++j) {
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1]; // i 번째 문자 == j 번째 문자 -> i-1, j-1에 있는거 그대로 갱신
            // 아닌 경
            else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+ 1;
        }
    }
    cout << dp[a_length][b_length];
    return 0;
}

// 풀이
// 편집 거리 알고리즘 (Edit Algorithm)