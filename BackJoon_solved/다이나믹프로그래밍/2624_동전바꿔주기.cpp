#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
using pii = pair<int ,int>;
int T, k;
int dp[10001]; //dp[i] : i원일 떄 가질 수 있는 동전 경우의 수
vector<pii> coins;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    cin >> k;
    coins.resize(k);
    for (pii &coin : coins) {
        cin >> coin.first >> coin.second;
    }
    dp[0] = 1;
    int coinValue, amount;
    for (pii coin : coins) {
        tie(coinValue, amount) = coin; // 코인 선택
        for (int nowCost = T; nowCost >= 0; --nowCost) { // 역으로 동전 카운팅
            for (int cnt = 1; cnt <= amount; ++cnt) { // 제한된 개수를 가지고 경우의 수 카운팅
                if (nowCost >= coinValue * cnt) dp[nowCost] += dp[nowCost - coinValue * cnt];
            }
        }
    }
    cout << dp[T];
    return 0;
}

// 경우의 수가 앞에서 부터 탐색하면 중복되어 카운팅 됨.
// 따라서 오히려 역으로 탐색을 시작하여 중복 카운팅을 억제하는 것