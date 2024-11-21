#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
    string inp;
    cin >> inp;
    int cnt = 0;
    bool zerofound = false;

    for (int i = 0; i < inp.size(); i++) {
        if (inp[i] == '0') {zerofound = true;}
        else {
            cnt += inp[i] - '0';
        }
    }
    if (zerofound && (cnt%3 == 0 )) {
        sort(inp.begin(), inp.end(),greater<>());
        cout << inp;
    }
    else cout << -1;
    return 0;
}