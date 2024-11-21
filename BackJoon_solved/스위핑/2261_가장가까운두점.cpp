#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
#define f(a,b,c) for(int a = b; a <c; a++)
const int ipm = 1e5+1;
const int inf = 1e4;

typedef struct _cd {
    int x, y;
    _cd() {}
    _cd(int a, int b) : x(a), y(b) {}
    bool operator<(const _cd& a) const {
        if (y==a.y) return x < a.x;
        return y < a.y;
    }
    bool operator>(const _cd& a) const {
        if (y==a.y) return x > a.x;
        return y > a.y;
    }
    int operator*(const _cd& a) const {return (x-a.x)*(x-a.x) + (y-a.y)*(y-a.y);}
} cd;

bool comp(const cd &a, const cd &b) {return a.x < b.x;}

cd lst[ipm];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n ;cin >> n;
    f(i,0,n) {
        int x,y; cin >> x >> y; lst[i] = cd(x,y);
    }
    sort(lst,lst+n,comp);
    int ans = lst[0]*lst[1];
    set<cd> cord; //후보군
    cord.insert(lst[0]); cord.insert(lst[1]);
    int start_point = 0; // 기준점과 연산할 최초 연산 위치
    f(i,2,n) { // 기준점
        cd now = lst[i];
        while (start_point < i) { // x 좌표 갈라치기
            int dx = now.x - lst[start_point].x;
            if (dx*dx >= ans) { //볼 가치 없는 밖 --> 후보제거
                cord.erase(lst[start_point]);
                start_point++;
            }
            else break; //범위 안 --> 구간탐색 종료
        }

        int ry = (int)sqrt(ans) +1; // range y value
        cd low = cd(-inf, now.y - ry), high = cd(inf, now.y + ry);
        auto l = cord.lower_bound(low), r = cord.upper_bound(high);

        for (auto it = l; it != r; ++it) ans = min(ans, (*it)*now);
        cord.insert(now);
    }
    cout << ans;
    return 0;
    
}