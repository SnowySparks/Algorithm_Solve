#include <iostream>
#include <deque>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,l; cin >> n >> l;
    deque<pair<int, int> > dq;
    int tmp;
    for (int i = 1 ; i <= n; i++) {
        cin >> tmp;
        while (!dq.empty() && dq.back().second >= tmp) dq.pop_back();
        while (!dq.empty() && dq.front().first < i-l+1 ) dq.pop_front();
        dq.push_back({i,tmp});
        cout << dq.front().second <<' ';
    }
    return 0;
}