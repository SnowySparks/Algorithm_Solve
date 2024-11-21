#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n; int cnt = 0;
    for (int i = 666;;i++){
        int tmp = i;
        while(tmp>=666) {
            if (tmp%1000 == 666) {
                cnt++; break;
            }
            tmp/=10;
        }
        if (cnt == n) {
            cout << i;
            break;
        }
    }
    return 0;
}