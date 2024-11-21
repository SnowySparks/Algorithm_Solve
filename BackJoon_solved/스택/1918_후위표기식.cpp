#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//우선순위
int pr(char a) {
    if (a == '+' || a == '-') return 1;
    else if (a == '*' || a == '/') return 2;
    else if (a == '(' || a == ')') return -1;
    else return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string inp;
    cin >> inp;
    stack<char> oper;
    string answer = "";

    for (int i = 0; i < inp.size(); i++) {
        if (pr(inp[i])==0) answer = answer + inp[i]; // 피연산자
        else {
            if (oper.empty()) oper.push(inp[i]);//스택이 빈경우
            else if (inp[i] == '(') oper.push(inp[i]); // ( 스택
            else if (inp[i] == ')') { // ) -> ( 나올때까지 전부 pop
                while (oper.top()!='(') {
                    answer = answer + oper.top();
                    oper.pop();
                }
                oper.pop();
            }
            else { //연산자
                if (pr(oper.top()) < pr(inp[i])) {
                    oper.push(inp[i]);
                }
                else {
                    while (!oper.empty() && pr(oper.top()) >= pr(inp[i])) {
                        answer = answer + oper.top();
                        oper.pop();
                    }
                    oper.push(inp[i]);
                }
            }
        }
    }
    while (!oper.empty()) {
        answer = answer + oper.top();
        oper.pop();
    }
    cout << answer ; return 0;
}   