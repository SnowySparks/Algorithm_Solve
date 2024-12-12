#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int inf = 1e9 + 1;
using pii = pair<int ,int>; // pair< 값, 반 위치>

int N, M;
int student[1001][1001]; // [반][학생 index]
int pointer[1001]; // 각 반마다의 index;
int ans = 1e9 + 1;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int minVal = inf,  maxVal = -inf; //최소, 최대 값

    cin >> N >> M;  // N: 학급 수, M: 학생 수
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // 입력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> student[i][j];
        }
        sort(student[i], student[i] + M); // 오름차순 정렬 - 각 반
        maxVal = max(maxVal, student[i][0]); // 각 반의 최소값들 중 최대값
        pq.push({student[i][0], i}); // push
    }
    ans = min(ans, maxVal - pq.top().first); // 처음 위치에 대한 답 갱신

    while (pq.size() == N) // 무조건 각 연산마다 1개의 반 총 N개의 데이터가 있어야 유효
    {   
        int value = pq.top().first, classIndex = pq.top().second; pq.pop();
        ++pointer[classIndex];
        if (pointer[classIndex] >= M) break; // 포인터 이동 후 해당 포인터 위치값이 유효한가에 대한 판단

        // 새로운 반 포인터에 대한 값에 대한 계산 -> 최대값 갱신 및 우선순위 큐에 저장
        maxVal = max(maxVal, student[classIndex][pointer[classIndex]]);
        pq.push({student[classIndex][pointer[classIndex]], classIndex});
        ans = min(ans, maxVal - pq.top().first);

    }
    cout << ans;
    return 0;
}

// 기본 원리
// 해당 문제에서는 각 그룹별 대표의 최대 - 최소 값의 최소를 구해야 하는 문제
// 일반적으로 가장 쉽게 생각할 수 있는 건 각 그룹별 최소값들끼리의 비교,
// 여기서 각 그룹별 대표들 중에 가장 작은 값을 가진 대표의 반을 찾아 그 포인터를 한 칸 옮기는 방식
// 즉 여기선 투 포인터가 아닌 총 최대 N개의 포인터를 두는 방식
// 이 원리는 최대 O(N^3) 가능성이 있음

// 추가 원리
// 기본적으로 포인터가 정해진 대로 for 구문을 돌려서 최소값을 확인하였음

//         for (int i = 0; i < N; ++i) { // 각 반 자체를 로테이트

//         // 최소값이 갱신되면 갱신 및 그 반 위치 포인터 지정
//             if (minVal > student[i][pointer[i]]) {
//                 minVal = student[i][pointer[i]];
//                 minValIndex = i;
//             }
//             maxVal = max(maxVal, student[i][pointer[i]]);
//         }
// 하지만 이렇게 하면 겹치는 정보에 대해서도 전부 다시 탐색해야 하는 문제가 발생
// 따라서 굳이 이렇게 for 문 보다는 우선순위 큐를 이용해서 정보의 활용성을 높이는 방식
// 우선순위 큐를 이용하면 가장 최소값을 찾는 것에서 O(1), 그리고 정보 갱신에 O(logN) 이 걸리는 원리
// 해당 방식을 이용하면 최악의 경우라도 O(N^2 lg(N^2)) 이 되므로 매우 안정적