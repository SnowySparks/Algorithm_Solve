#include <vector>
#include <iostream>
using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
} // (12) x (13)

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    int r = ccw(x1,y1,x2,y2,x3,y3);
    r = (r > 0 ? 1 : (r <0 ? -1 : 0));
    cout << r; return 0;
}