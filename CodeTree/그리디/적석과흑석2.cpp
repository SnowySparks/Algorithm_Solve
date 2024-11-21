#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define f(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
#define pii pair<int, int>

const int inf = 1e9 + 7;
int n, m;
set<int> red;
vector<pii> black;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    black.resize(m);
    f(i,0,n) {
        int tmp; cin >> tmp;
        red.insert(tmp);
    }
    f(i,0,m) {
        cin >> black[i].first >> black[i].second;
    }
    // 최대값을 오름차순, 동일 최대값은 시작값 내림차순 (탐색 구간 크기가 가장 작은걸 우선적으로)
    sort(black.begin(), black.end() , [](const pii &a, const pii &b) {
        return (a.second == b.second ? a.first > b.first : a.second < b.second);
    }
    );

    int ans = 0;

    f(i, 0, m) {
        if (red.empty()) break;
        auto val = red.lower_bound(black[i].first);
        if (*val <= black[i].second && *val >= black[i].first) {
            ++ans;
            red.erase(*val);
        }
    }
    cout << ans;
    return 0;
}

//빨간색 돌 정수 R, 그리고 검은석 돌 범위 A, B 범위 주어질때 A <= R <= B 만족하는 빨간 - 검은색 돌 매칭을 최대로 만드는 문제
// 원리 : 검은돌 순서를 "끝지점은 오름차순, 동일 끝지점 대애선 시작지점 내림차순"

// 이유 : 끝지점을 오름차순 이유는 마치 회의실 배정 문제와 같음
// 시작지점을 내림차순으로 두는 이유 : 구간을 가장 쫍은걸 먼저 탐색함으로써 그 확률을 높이기 위함