#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct pts {
    int x, y, px, py;
    pts(int x = 0, int y = 0) : x(x), y(y), px(0), py(0) {} // 생성자 1
    pts(int x, int y, int px, int py) : x(x), y(y), px(px), py(py) {} //생성자 2
    void cal_frompts(int ptx, int pty) { //해당 포인트 기준 (ptx pty) 해당 객체 벡터값
        px = x - ptx;
        py = y - pty;
    }

    bool operator<(const pts &oth) const {
        if (py * oth.px != px * oth.py) return py * oth.px < px * oth.py;
        if (y != oth.y) return y < oth.y;
        return x < oth.x;
    }
};

int ccw(const pts &a, const pts &b const pts &c) {
    
}

int n;
pts arr[100001];
vector<pts>  convexhull;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].x >> arr[i].y;
        if (i && arr[i] < arr[0]) {
            swap(arr[i], arr[0]);
        }
    }
    for (int i = 1; i < n; ++i) arr[i].cal_frompts(arr[0].x, arr[0].y);
    sort(arr + 1, arr + n);
    convexhull.push_back(arr[0]);
    convexhull.push_back(arr[1]);

    for (int i = 2;)
    return 0;
}