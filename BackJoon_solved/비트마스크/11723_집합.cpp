#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string a;
    int b;
    int dt = 0;

    int N; cin >> N;
    while (N--) {
        cin >> a;
        if (a == "add") {
            cin >> b;
            dt |= (1 << (b));
        }
        else if (a == "remove") {
            cin >> b;
            dt &= ~(1 << (b));
        }
        else if (a == "check") {
            cin >> b;
            if (dt & (1 << (b))) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (a == "toggle") {
            cin >> b;
            dt ^= (1 << b);
        }
        else if (a == "all") {
            dt = (1 << 21) - 1;
        }
        else if (a == "empty") {
            dt = 0x0;
        }
    }
}