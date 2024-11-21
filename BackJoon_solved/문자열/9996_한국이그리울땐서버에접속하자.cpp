#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string inp; cin >> inp;
    string reg = "";

    for (char a : inp) {
        if (a >= 'a' && a <= 'z') reg+=a;
        else reg+="[a-z]*";
    }
    regex s2(reg);
    for (int i = 0; i < n; i++) {
        string s ; cin >> s;
        cout << (regex_match(s,s2) ? "DA\n" : "NE\n");
    }
    return 0;
}