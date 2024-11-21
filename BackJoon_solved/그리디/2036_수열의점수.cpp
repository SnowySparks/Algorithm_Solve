#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> minus;
    vector<int> plus;
    vector<int> one;
    long long ans = 0;
    int one_cnt = 0;
    int n; cin >> n;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp > 1) plus.push_back(tmp);
        else if (tmp == 1) one_cnt++;
        else minus.push_back(tmp);
    }
    sort(plus.begin(), plus.end(), greater<>() );
    sort(minus.begin(), minus.end());

    int idx = 0;
    for (; idx < plus.size(); idx += 2) {
        if (idx == (int)plus.size() -1 ) {
            ans += plus[idx];
            break;
        }
        ans += 1LL * plus[idx] * plus[idx + 1];
    }

    idx = 0;

    for (; idx < minus.size(); idx += 2) {
        if (idx == (int)minus.size() -1 ) {
            ans += minus[idx];
            break;
        }
        ans += 1LL * minus[idx] * minus[idx + 1];
    }
    cout << ans + one_cnt;
    return 0;
}

// 원리
// 0 이하들 숫자들 모아서 정렬시키고 , 가장 작은수 2개씩 곱한걸 답 더하기 (단 마지막 수가 남을 경우 그건 더해야 함)
// 1 숫자는 예외적으로 곱해도 이득이 없으니 차라리 모아서 다 더해버리기
// 2 이상 수들은 0 이하들 수 모으듯이 모아서 또 큰수 2개씩 곱한걸 더하면 됨