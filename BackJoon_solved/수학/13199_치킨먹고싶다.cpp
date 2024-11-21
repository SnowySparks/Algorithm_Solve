#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N ; cin >> N;
    int p,m,f,c;
    int non_d= 0, d= 0; //no 단골, 단골
    int cp; //쿠폰
    while ( N--) {
        cp = 0;
        cin >> p >> m >> f >> c;
        non_d = m/p + (m/p *c/f); //노단골 치킨 개수
        d = m/p;//돈으로 산 단골 치킨 개수
        
        cp = m/p * c;//첫 쿠폰 개수 

        if (cp >= f) { // 쿠폰 개수가 최소 개수보다 큰 경우
            d += (cp - f) / (f - c) + 1;
            // f쿠폰 주고 , c만큼 쿠폰 얻음. (전체적을 보면 f-c만큼 치킨 구매)
            // 단 "1회 미리 했다고 가정하고" 계산
        }
        cout << d - non_d <<'\n';
    }
}