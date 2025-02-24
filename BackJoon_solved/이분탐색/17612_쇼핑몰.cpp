#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int ,int>;
pii arr[100000];
int n, k;
struct info {
    int cashIdx; long long id, t;
    bool operator<(const info &other) const {
        if (t == other.t) return cashIdx > other.cashIdx;
        return t < other.t;
    }
    bool operator>(const info &other) const {
        if (t == other.t) return cashIdx < other.cashIdx;
        return t > other.t;
    }
};
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    long long answer = 0;
    priority_queue<info, vector<info>, greater<> > pq;
    priority_queue<int, vector<int>, greater<> >lst;
    for (int i = 0; i < min(k, n); ++i) {
        pq.push({i+1, arr[i].first, arr[i].second});
    }
    long long t = 0;
    long long cnt = 0;
    for (int i = min(k, n); i < n; ++i) {
        if (lst.empty()) {
            t = pq.top().t;
            while (!pq.empty() && pq.top().t == t) {
                answer += (++cnt)*pq.top().id;
                lst.push(pq.top().cashIdx);
                pq.pop();
            }
        }
        pq.push({lst.top(),arr[i].first,t+arr[i].second});
        lst.pop();
    }
    while (!pq.empty()) {
        answer += (++cnt)*pq.top().id;
        pq.pop();
    }
    cout << answer;
    return 0;
}