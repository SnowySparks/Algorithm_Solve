#include <iostream>
#include <vector>
using namespace std;

long long ra[46], rb[46];
int main(void) {
    int N; cin >> N;
    ra[1] = 0;
    rb[1] = 1;
    ra[2] = 1;
    rb[2] = 1;
    for (int i = 3 ; i <= N ; i++) {
        ra[i] = rb[i-1];
        rb[i] = ra[i-1] + rb[i-1];
    }
    cout << ra[N]<<' ' << rb[N]; return 0;
}