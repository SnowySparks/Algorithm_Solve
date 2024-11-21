#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int r = n * (n+1)/2;
    cout << r << '\n' << r*r << '\n' << r*r;
    return 0;
}