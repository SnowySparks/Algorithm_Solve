#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
pair<int, int> dt[300001];
int bags[300001];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K; cin >> N >> K;
    for (int i = 0 ; i < N ; i++) cin >> dt[i].first >> dt[i].second;
    for (int s = 0 ; s < K ; s++) cin >> bags[s];
    long long ans = 0;
    sort(dt, dt+N); sort(bags, bags+K);
    priority_queue<int, vector<int>, less<int> > pq;
    int loc = 0;
    for (int i = 0; i < K ; i++) {    
        while(loc < N && bags[i] >= dt[loc].first) {
            pq.push(dt[loc++].second);
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}