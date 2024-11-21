#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> dp(1000001);
vector<long long> sum(1000001);

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill (dp.begin(), dp.end(), 1);

    // 2를 예를 들면, 2를 인수로 갖는 모든 수에다가 값을 일일이 그 값을 더함
    for (int i = 2 ; i <= 1000000; i++) {
        for (int j = 1 ; j*i<= 1000000 ; j ++) {
            dp[j*i] += i;
        }
    }
    for (int i = 1 ; i <= 1000000 ; i ++) {
        sum[i] = sum[i -1 ] + dp[i];
    }

    int N; cin >> N;
    int temp;

    while (N--) {
        cin >> temp;
        cout << sum[temp] <<'\n';
    }
    return 0;
}