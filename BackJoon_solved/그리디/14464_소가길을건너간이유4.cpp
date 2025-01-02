#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
const int MAXN = 2e4 + 1;
int C, N; // 닭, 소
int chicken[MAXN];
pii cow[MAXN];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> C >> N;
    for (int i = 0; i < C; ++i) cin >> chicken[i]; // chicken
    for (int i = 0; i < N; ++i) cin >> cow[i].first >> cow[i].second; // 소(시작, 종료)
    sort(chicken, chicken+C);
    sort(cow,cow+N);

    int ans = 0;
    priority_queue<int, vector<int>, greater<int> > pq; // 소의 끝지점 저장하기 위한 곳
    for (int i = 0, t=0 ; i < C; ++i) {
        
        // 소 시작점이 chicken[i]보다 이전인 경우 모든 소 끝점 넣기
        while (t < N && cow[t].first <= chicken[i]) pq.push(cow[t++].second);
        // 소 끝점 < 치킨 있을 때 시간 -> 그 소는 더이상 가망없음
        while (!pq.empty() && chicken[i] > pq.top()) pq.pop();

        if (!pq.empty()) {
            // 남아있는 소들 중 끝점이 가장 최소인 것이 배정
            ++ans;
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}

// 원리
// 먼저 소들은 시작점 기준으로 오름차순 정렬, 닭도 오름차순 정렬
// 닭은 순차 탐색하여, 다음과 같이 진행
// 먼저 해당 닭 기준으로 소 시작범위 <= 닭 인 모든 부분 다 Pq에 넣기(끝점)
// 그리고 끝점이 닭 위치보다 작은 것들 다 pop
// 그래도 남아있으면 그중 하나를 Pop