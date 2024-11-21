#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
const int inf = 1e9 + 7;
using pll = pair<long long, long long >;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int n; cin >> n;
    long long ans = 0;
    string s;
    vector<pll> dt(n);
    f(i, 0, n) {
        cin >> s;
        for (char ch : s) {
            if (ch == '(') dt[i].first++;
            else {
                dt[i].second++;
                ans +=dt[i].first;
            }
        }
    }

    sort(dt.begin(), dt.end(), [](const pll &a, const pll &b) {
        return a.first * b.second > a.second * b.first;
    });

    long long cnt = 0;
    for (auto &[open, close] : dt) {
        ans += close*cnt;
        cnt += open;
    }
    cout << ans;
    return 0;
}

// 해당 문제 그리디적 해결 : 두 문자열 s1, s2의 열린 , 닫힌 개수를 카운팅하고
// s1열린 개수 * s2닫힌 갯수 > s1닫힌 갯수 * s2 열린 갯수 로 정렬

// 소괄호로만 이루어진 문자열 n개가 주어집니다. 이들을 적절하게 붙여 하나의 문자열 T로 만들어 얻을 수 있는 점수를 최대화 하려고 합니다. 이때, 문자열 T의 점수는 문자열 내 서로 다른 두 문자를 골랐을 때, 왼쪽에 있는 문자는 '(', 오른쪽에 있는 문자는 ')'인 가지수로 정의됩니다.

// 예를 들어 문자열 )(()()) 는 다음의 이유로 8점을 얻게 됩니다.