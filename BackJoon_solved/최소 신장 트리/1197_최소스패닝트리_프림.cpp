#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e;
vector<pair<int ,int> > gh[10001]; // 비용, 노드 방식
bool inin[10001]; //MST에 포함되었는가 안되었는가?
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> v >> e;
    int a, b, c;
    for (int i = 0 ; i < e; ++i) {
        cin >> a >> b >> c;
        gh[a].push_back({c, b});
        gh[b].push_back({c, a});
    }
    int ans = 0;
    priority_queue<pair<int ,int> > pq;
    inin[1] = true;
    int cnt = 1;
    //시작 노드에 대한 간선 정보 미리 입력
    for (auto &[cost, nxt] : gh[1]) {
        pq.push({-cost, nxt});
    }
    while (!pq.empty() && cnt < v)
    {
        //추출
        int loc = pq.top().second;
        int weight = -pq.top().first;
        pq.pop();
        if (inin[loc]) continue; // 이미 해당 노드는 MST안에 포함된 상태니 무시해야함

        //아닌 경우 해당 노드는 MST에 포함시키고 그 비용을 가산함
        inin[loc] = true;
        ans += weight;
        ++cnt;

        //다음 연결 대상을 찾아 우선순위 큐에 삽입. 다음 연결 대싱이 이미 MST에 포함된건 배제하고 그 대상에 넢기
        for (auto &[cost, nxt] : gh[loc]) {
            if (!inin[nxt]) {
                pq.push({-cost, nxt});
            }
        }
    }
    cout << ans;

    return 0;
}