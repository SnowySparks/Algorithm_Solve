#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int max_n = 100;
int n;
int arr[201];
int prefix_red[201];
int prefix_blue[201];
int dp[101][101][201]; //r개선택, b개선택, 그리고 idx번째까지 보았을 때 최대값
int red[201], blue[201];

int dfs(int r, int b, int idx) { //r개수, b개수, idx까지 살펴봄
    if (idx == 2*n) return 0;
    if (r == n) { //더이상 레드 불가능
        return prefix_blue[2*n] - prefix_blue[idx];
    }
    if (b == n) { //더이상 블루 불가능
        return prefix_red[2*n] - prefix_red[idx];
    }

    int &res = dp[r][b][idx];
    if (res != -1) return res;
    res = 0;
    res = max(dfs(r+1, b, idx+1) + red[idx+1], dfs(r, b+1, idx+1) + blue[idx + 1]);
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 2*n; ++i) cin >> red[i] >> blue[i];
    for (int i = 1; i <= 2*n; ++i) {
    prefix_red[i] = prefix_red[i-1] + red[i];
    prefix_blue[i] = prefix_blue[i-1] + blue[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0, 0);
    return 0;
}


// 2∗N 번에 걸쳐 시행을 반복하며 매 시행마다 빨간색, 파란색 총 2개의 카드가 주어지고 항상 두 색깔의 카드 중 하나의 카드를 선택해야만 합니다. 
// 각 카드에는 숫자가 적혀있고, 적절하게 카드를 골라 결과적으로 빨간색 카드를 N개, 파란색 카드를 N개 고른다고 했을 때 
// 뽑힌 숫자들의 합을 최대로 하는 프로그램을 작성해보세요.

// dp[i][j] -> red i개, 이때까지 j개쌍을 보았을 때 최대값, (이때 blue는 j-i개를 보게 되는 것과 같은 것이 됨)// dp[i][j] :
// i번째 카드 쌍까지 고려해봤을 때
// 지금까지 빨간색 카드를 정확히 j장 뽑았다 했을 때
// 얻을 수 있는 뽑힌 숫자들의 최대 합 . dp[2 * n][n] 가 답이 됨


// 그리디도 가능
// 처음에 모든 걸 빨간색으로 되어 있다 치고 파란색을 어떤 걸로 교체해야 하는가?
// 이때 red[i] - blue[i] 가 작은 (즉 차이 대비 블루쪽이 큰 것)을 n개 우선적으로 선택하는 것
