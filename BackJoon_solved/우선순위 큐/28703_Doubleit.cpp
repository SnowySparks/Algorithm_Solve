#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int mv=-1, ans; int tmp;
    priority_queue <int, vector<int> , greater<> > pq;
    for (int i = 0 ; i < n ; i++) {
        cin >> tmp;
        mv = max(mv,tmp);
        pq.push(tmp);
    }
    int curmax = mv; ans = mv - pq.top();
    while (mv > pq.top()) {
        int loc = pq.top(); pq.pop();
        ans = min (ans , curmax - loc);
        curmax = max(curmax, loc*2);
        pq.push(loc*2);
    }
    ans = min(ans, curmax - pq.top());

    cout << ans;return 0;
}