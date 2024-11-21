#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int,int>;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >>n;
    vector<pii> lst(2*n);
    for (int i = 0; i <n; ++i) {
        cin >> lst[2*i].first >> lst[2*i+1].first;
        lst[2*i].second = 1;
        lst[2*i+1].second = -1;
    }
    sort(lst.begin(), lst.end()); //끝점은 포함을 안하기에, 끝점 처리가 먼저 필수적으로 선행되어야함.
    //단 마지막은 어차피 1개가 확정적으로 있으니 마지막에 대한 답 적용 (1 -> 0)은 필요가 없음.
    int cnt = 0;
    int ans = 0;
    for (pii &a : lst) {
        ans = max(cnt, ans);
        cnt += a.second;
    }
    cout << ans;
    return 0;
}