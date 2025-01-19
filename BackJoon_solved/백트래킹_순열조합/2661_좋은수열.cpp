#include <iostream>
#include <algorithm>
using namespace std;

int n;
string res = "";

bool ok() {
    if (res.size() <= 1) return true;
    int length = res.size();
    int maxLen = length / 2;

    for (int len = 1; len <= maxLen; ++len) {
        for (int idx = 0; idx <= length- 2*len; ++idx) {
            if (res.substr(idx, len) == res.substr(idx+len,len)) return false;
        }
    }
    return true;
}

void back_track(int idx) {
    if (idx == n) {
        cout << res;
        exit(0);
    }
    for (int i = 1; i <=3; ++i) {
        res.push_back(char('0' + i));
        if (ok()) {
            back_track(idx+1);
        }
        res.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    back_track(0);
    return 0;
}