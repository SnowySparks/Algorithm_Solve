#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int inp;
    int maximun = -10000;
    int r=0,c=0;

    for (int i = 0 ; i < 9 ; i++) {
        for (int j = 0 ; j < 9 ; j++) {
            cin >> inp;
            if (maximun < inp) {
                maximun = inp;
                r= i+1;
                c=j+1;
            }
        }
    }
    cout << maximun << '\n';
    cout << r << ' ' << c << '\n';
    return 0;
}