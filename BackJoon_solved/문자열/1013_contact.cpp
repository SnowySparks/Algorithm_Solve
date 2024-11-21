#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string s ; cin >> s;
        regex s2("(100+1+|01)+");
        cout << (regex_match(s,s2) ? "YES\n" : "NO\n");
    }
    return 0;
}