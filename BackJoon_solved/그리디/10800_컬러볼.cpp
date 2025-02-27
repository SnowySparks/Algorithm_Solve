#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
struct info {
    int idx, c, s, score; //공번호, 색, 크기, 답
};
const int N = 2e5;
int n;
int colorTotalSize[N+1] ={0, };
int weightCnt[2001] = {0, };

info balls[N];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    // input
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> balls[i].c >> balls[i].s;
        balls[i].idx = i;
    }
    // 크기 오름차순
    sort(balls, balls+n, [](const info &a, const info &b){
        return a.s < b.s;
    });

    int pinPoint = 0; // 이쪽 사이즈 기준으로
    int totalSize = 0;// 작은 공 사이즈들
    for (int i = 0; i < n; ++i) {
        // 동일 사이즈는 배제
        // 핀 포인트 < i 이면서, i보다 사이즈 작은 핀포인트에 대해서 모든 사이즈 더하기 (토탈, 각 컬러별의 총합)
        while (pinPoint < i && balls[pinPoint].s < balls[i].s) {
            colorTotalSize[balls[pinPoint].c] += balls[pinPoint].s;
            totalSize += balls[pinPoint].s;
            ++pinPoint;
        }
        // 총 사이즈에서 동일 컬러 사이즈 제거한 것이 그 공의 정답
        balls[i].score = totalSize - colorTotalSize[balls[i].c];
    }
    // 인덱스정렬
    sort(balls, balls+n, [](const info &a, const info &b){
        return a.idx < b.idx;
    });

    // 출력
    for (int i = 0; i < n; ++i) {
        cout << balls[i].score << '\n';
    }

    return 0;
}