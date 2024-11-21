#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long sum = 0;
    long long xorsum = 0;

    int cmd; long long x;
    int M; cin >> M;

    while(M--) {
        cin >> cmd;
        if (cmd == 1 || cmd == 2) cin >> x;
        if (cmd == 1) {
            sum+=x;
            xorsum^=x;
        }
        else if (cmd == 2) {
            sum -= x;
            xorsum ^= x;
        }
        else if (cmd == 3) {
            cout << sum <<'\n';
        }
        else {
            cout << xorsum <<'\n';
        }
    }
    return 0;
}