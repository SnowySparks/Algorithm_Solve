#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int ,int>;
int typeCnt = 0;
vector<pii> lst[6];
int mentoCnt[6] = {0, 1, 1, 1, 1, 1};
int ans = 1e9 + 7;
int waitTime(int loc) {
    int nowTime = 0;
    int res = 0;
    priority_queue<int, vector<int>, greater<> > pq;
    
    for (auto &[enterTime, duration] : lst[loc]) {
        while (pq.size() >= mentoCnt[loc] ) {
            nowTime = max(nowTime, pq.top());
            pq.pop();
        }
        if (nowTime <= enterTime) {
            nowTime = enterTime;
            nowTime = enterTime;
            pq.push(enterTime + duration);
        }
        else {
            res += nowTime - enterTime;
            pq.push(nowTime + duration);
        }
    }
    return res;
}

int totalWait() {
    int cal = 0;
    for (int i = 1; i <= typeCnt; ++i) {
        cal += waitTime(i);
    }
    return cal;
}

void back_track(int idx, int remain) {
    if (idx == typeCnt) {
        mentoCnt[idx] += remain;
        ans = min(ans, totalWait());
        mentoCnt[idx] -= remain;
        return;
    }
    for (int i = 0; i <= remain; ++i) {
        mentoCnt[idx] += i;
        back_track(idx+1, remain-i);
        mentoCnt[idx] -= i;
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    typeCnt = k;
    sort(reqs.begin(), reqs.end(), [](const vector<int>&a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    for (const vector<int> &req : reqs) {
        lst[req[2]].push_back({req[0], req[1]});
    }
    
    back_track(1, n-k);
    return ans;
}