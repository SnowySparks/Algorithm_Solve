#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;
#define f(a,b,c) for(int a=b; a<c;a++)

vector<string> resplit(const string &s, string pattern = " ") {
    regex re(pattern);
    sregex_token_iterator it(s.begin(), s.end(), re, -1), end;
    return vector<string>(it, end);
}

int oper(int a, int b, string op = "+") {
    if (op == "+") return a + b;
    else return a - b;
}
int oper(int a, int b, char op = '+') {
    if (op == '+') return a + b;
    else return a - b;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s ; cin >> s;
    vector<string> numlst = resplit(s,"[+-]");
    vector<string> op= resplit(s,"[\\w\\s]+");
    if (op[0] == "") op.erase(op.begin());

    vector<int> num;
    for (int i = 0; i < numlst.size(); i++) {
        num.push_back(stoi(numlst[i]));
    }

    if (numlst.size() == 1) {
        cout << numlst.front(); return 0;
    }
    else if (numlst.size() == 2) {
        cout << oper(num[0], num[1], op.front());
    }
    else {
        int loc = 0;
        int ans = num[0];
        while(loc < op.size() && op[loc]=="+") {
            ans = oper(ans, num[loc+1], op[loc] );
            loc++;
        }

        while( loc < op.size()) {
            ans = oper(ans, num[loc+1], "-");
            loc++;
        }

        cout << ans;
    }


    return 0;
}