#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
typedef pair<int, int> pii;
const int N = 5e5 + 1;
const int INF = 1e9 + 7; //
int order[N]; // 사용순서, [t] 
deque<int> useAtTime[N]; // [아이템] 마다 사용시간
bool isAlreadyUsing[N]; //사용중인 상태인지
priority_queue<pii> pq; // 다음 있을 위치, 아이템


void useItem(int item, int t) {
    while ( !useAtTime[item].empty() && useAtTime[item].front() <= t) {
        useAtTime[item].pop_front();
    }
    if (useAtTime[item].empty()) {
        pq.push({INF, item});
    }
    else {
        pq.push({useAtTime[item].front(), item});
    }
    isAlreadyUsing[item] = true;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ans = 0;
    int cnt = 0; // 실제 들어간 것
    int n, k; cin >> n >> k;

    for (int t = 1; t <= k; ++t) {
        cin >> order[t];
        useAtTime[ order[t] ].push_back(t);
    }

    if (n >= k) {
        cout << 0;
        return 0;
    }


    for (int t = 1; t <= k; ++t) {
        int item = order[t];
        // 이미 꼽힘 -> 갱신 필요성
        if (isAlreadyUsing[item]) {
            useItem(item, t);
            continue;
        }

        if (cnt < n) {
            useItem(item, t);
            ++cnt;
            continue;
        }

        // 완전 꽉찼는 경우
        int lastItem = pq.top().second; pq.pop();
        isAlreadyUsing[lastItem] = false;
        ++ans;
        useItem(item, t);
    }
    cout << ans;

    return 0;
}