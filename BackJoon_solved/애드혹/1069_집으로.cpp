#include <iostream>
#include <cmath>
using namespace std;

double min(double a, double b) {
    return (a<b)?a:b;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, y, d, t;
    cin >> x >> y >>d >> t;
    double dst = pow( x*x + y*y, 0.5); // distance
    int jp = dst/d; // 나머지 제외 점프 횟수
    double left = dst - jp*d; // 점프 jp회 하고 남은 구간 길이
    double ans = min(dst, jp* t +left); //그냥 걷기 점프 jp번 하고 나머지 걷기 
    ans = min(ans,(jp+1)*t + (d-left)); //점프 jp+1하고 돌아가기
    if (jp>0) ans = min(ans , (jp+1)*t); // 방향약깐 틀어서 
    if (dst < d) ans = min(ans, t*2.0); // 0회 계산이면 약깐 방향 틀어서 점프2회
    cout << fixed;
    cout.precision(10);
    cout << ans;
    return 0;
}