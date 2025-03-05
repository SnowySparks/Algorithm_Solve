#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct Box {
    int b, h, w, d;
};
Box box[50000];
double v;

double cal(double mid) {
    double res = 0;
    for (int i = 0; i < n; ++i) {
        if (box[i].b + box[i].h <= mid) res += (double)box[i].w*box[i].h*box[i].d;
        else if (mid > box[i].b) res += (double)(mid-box[i].b)*box[i].w*box[i].d;
    }
    return res;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    double l = 0, r = 0, mid = 0;
    for (int i = 0; i < n; ++i) {
        cin >> box[i].b >> box[i].h >> box[i].w >> box[i].d;
        r = max(r, (double)(box[i].b + box[i].h) );
    }
    cin >> v;
    if (cal(r) < v) {
        cout << "OVERFLOW";
        return 0;
    }
    while (l + 0.001 < r) {
        mid = (l + r)/2;
        if (cal(mid) >= v) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << fixed;
    cout.precision(2);

    cout << r;
}