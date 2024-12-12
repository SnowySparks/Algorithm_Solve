#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 1e9 + 1;

int N, M;
int student[1001][1001]; 
int pointer[1001]; // 각 반마다의 index;
int ans = 1e9 + 1;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;  // N: 학급 수, M: 학생 수

    // 입력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> student[i][j];
        }
        sort(student[i], student[i] + M); // 오름차순 정렬 - 각 반
    }

    int minVal, maxVal;
    int minValIndex; // 한 루트 내에서 최소값에 만족하는 inDex
    bool stop = false; // 루프 종료 조건 부합 -> pointer들 값 중 하나라도 M이 되는 순간 true
    while (true)
    {
        minVal = inf; maxVal = -inf; // 최소, 최대값의 초기화
        for (int i = 0; i < N; ++i) { // 각 반 자체를 로테이트

        // 최소값이 갱신되면 갱신 및 그 반 위치 포인터 지정
            if (minVal > student[i][pointer[i]]) {
                minVal = student[i][pointer[i]];
                minValIndex = i;
            }
            maxVal = max(maxVal, student[i][pointer[i]]);
        }

        ans = min(ans, maxVal - minVal); // 답 갱신

        if (++pointer[minValIndex] >= M) {
            break;
        } 
    }
    
    cout << ans;

    return 0;
}