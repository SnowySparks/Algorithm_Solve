#include <iostream>
using namespace std;

int main(void) {
    int x, y, w, s;
    scanf("%d %d %d %d",&x, &y, &w, &s);
    x = abs(x); y=abs(y);
    if (2*w <= s) {
        printf("%lld", (1LL*(x+y)*w));
    }
    else {
        long long max_v = max(x, y), min_v= min(x, y);
        long long left = max_v - min_v;
        long long mv = min_v * s;

        if (w <= s) mv += (left * w);
        else mv += (left/2*2*s) + (left&1)*w;
        printf("%lld", mv);
    }
    return 0;
}

// //원리
// 1. 직선거리 비용 *2 <= 대각선 비용 : 무조건 직선거리로 이동

// 아닌 경우 일단 min(x,y)만큼 대각선으로 이동

// 1. 의 아닌 경우 중에서
//     1. 직선 거리비용 <= 대각선 비용 : 나머지 부분 직선으로 이동
//     2. 아닌 경우, ( 대각선 2번 == 직선 2번 이동) 이므로, 나머지 거리 /2 *2 * 대각선비용 + 나머지거리 % 2 * 직선비용