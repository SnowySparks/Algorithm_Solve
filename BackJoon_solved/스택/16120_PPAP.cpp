#include <iostream>
#include <cstring>
using namespace std;

char ch[4] = {'P','P','A','P'};
bool isPPAP(string &str) {
    int len = str.size()-1;
    for (int i = 0; i < 4; ++i) {
        if (str[len-(3-i)]!=ch[i]) return false;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string inp; cin >> inp;
    string stack = "";

    for (char ch : inp) {
        stack.push_back(ch);
        while (stack.size() >= 4 && isPPAP(stack))
        {
            for (int i = 0; i < 4; ++i) stack.pop_back();
            stack.push_back('P');
        }
    
    }
    cout << (stack == "P" ? "PPAP" : "NP");
    return 0;
}