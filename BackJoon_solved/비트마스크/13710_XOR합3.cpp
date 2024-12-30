#include <iostream>
#include <algorithm>
using namespace std;
using ll = unsigned long long;
ll bitArr[31];
int n;
ll ans = 0;
ll cnt[2][30]; // (1 or 0) {i번째 비트}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    int input = 0, preXOR = 0;

    for (int i = 0; i < 30; ++i) {
        cnt[0][i] = 1; // 0번째 수, 0에 대한 처리
        bitArr[i] = (1 << i);
    }

    for (int i = 0; i < n; ++i) {
        cin >> input;
        preXOR ^= input;
        for (int bit = 0; bit < 30; ++bit) {
            int state = (preXOR & bitArr[bit]) > 0 ? 1 : 0;
            cnt[state][bit]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 30; ++i) {
        ans += ( (cnt[1][i]*cnt[0][i] ) * bitArr[i] );
    }
    cout << ans;
 
    return 0;
}

// 원리
// XOR 누적합을 이용 + 행성 3 문제
// XOR 누적의 결과와 bitmasking의 1,0 카운팅을 이용
// 단 0번째 수 = 0 일 때, 이에 대한 계산을 미리 해 둬야함