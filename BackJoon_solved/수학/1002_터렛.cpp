#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    int N; cin >> N;
    int x1, y1, r1, x2, y2, r2;
    double dist;
    while(N--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        dist = pow(abs(x1-x2),2) + pow(abs(y1-y2),2);
        dist = pow(dist,0.5);
        
        if (dist < r1 + r2 && dist > abs(r1-r2)) cout << 2;
        else if (dist < abs(r1- r2)) cout << 0;
        else if (dist > r1+r2) cout << 0;
        else if (x1 == x2 && y1 == y2 && r1 == r2) cout << -1;
        else cout << 1;
        cout << '\n';
    }

}