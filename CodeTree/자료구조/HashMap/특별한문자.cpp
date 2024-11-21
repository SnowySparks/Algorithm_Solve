#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unordered_map<char, int> dt;
    string s; cin >> s;
    for (char &ch : s) dt[ch]++;
    char ch = '~';
    for (char &c : s) {
        if (dt[c] == 1) {
            ch = c;
            break;
        }
    }
    if (ch == '~') cout <<"None";
    else cout << ch;

}