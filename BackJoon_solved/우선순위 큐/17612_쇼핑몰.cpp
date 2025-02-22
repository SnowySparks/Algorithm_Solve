#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int ,int>;
int n, k;
pii arr[100000];
struct info {
    int cashIdx; long long id, t;
    bool operator<(const info &other) const {
        if (t == other.t) return cashIdx > other.cashIdx;
        return t < other.t;
    }
    bool operator>(const info &other) const {
        if (t == other.t) return cashIdx > other.cashIdx;
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
    vector<info> ans;
    for (int i = 0; i < min(k, n); ++i) {
        pq.push({i+1, arr[i].first, arr[i].second});
    }
    for (int i = min(k, n); i < n; ++i) {
        long long t = pq.top().t; 
        int idx = pq.top().cashIdx;
        ans.push_back(pq.top());
        pq.pop();
        pq.push({idx, arr[i].first, t+1LL*arr[i].second});
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin(), ans.end(), [](const info &a, const info &b) {
        if (a.t == b.t) return a.cashIdx > b.cashIdx;
        return a.t < b.t;
    });
    for (long long i = 0; i < n; ++i) {
        answer += ans[i].id*(i+1);
    }
    cout << answer;
    return 0;
}