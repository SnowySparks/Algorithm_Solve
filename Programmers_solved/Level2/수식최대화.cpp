//
#include <string>
#include <vector>
#include <stack>

using namespace std;


vector<vector<char>> s {{'-','+','*'},{'-','*','+'},{'+','-','*'},{'+','*','-'},{'*','+','-'},{'*','-','+'}};

int priority(char x,vector<char> important) {
    for (int i=0;i<3;i++) {
        if (important[i]==x) {
            return i;
        }
    }
}

string to_postfix(string exp,vector<char> pty) {
    stack <char> oper;
    int len=exp.length();
    string postfix;

    for (int i=0;i<len;i++) {
        if (exp[i]>='0' && exp[i]<='9') {
            do {
                postfix.push_back(exp[i]);
                i++;
            } while (exp[i]>='0' && exp[i]<='9');
            postfix.push_back(' ');
            i--;
        }
        
        else if (exp[i]=='-'||exp[i]=='+'||exp[i]=='*') {
            while ((!oper.empty()) && (priority(exp[i],pty)>=priority(oper.top(),pty))) {
                postfix.push_back(oper.top());
                postfix.push_back(' ');
                oper.pop();
            }
            oper.push(exp[i]);
        }
    }

    while (!oper.empty()) {
        postfix.push_back(oper.top());
        oper.pop();
        postfix.push_back(' ');
    }
    return postfix;
}


long long solve_postfix(string postfix) {
    long long solve=0;
    long long temp=0;
    stack<long long> sp;
    long long op1,op2;

    for (int i=0;i<postfix.length();i++) {
        if (postfix[i]>='0' && postfix[i]<='9') {
            do {
                temp=temp*10+(postfix[i]-'0');
                i++;
            } while(postfix[i]>='0' && postfix[i]<='9');

            sp.push(temp);
            temp=0;
            i--;
        }
        else if (postfix[i]=='-' || postfix[i]=='+' || postfix[i]=='*') {
            op2=sp.top();
            sp.pop();
            op1=sp.top();
            sp.pop();
            
            switch (postfix[i]) {
                case '-':
                    sp.push(op1-op2);
                    break;
                case '+':
                    sp.push(op1+op2);
                    break;
                case '*':
                    sp.push(op1*op2);
                    break;
            }
        }
    }

    return sp.top();
}

long long solution(string expression) {
    long long answer=0;
    long long temp=0;
    for (auto i : s) {
        temp = solve_postfix(to_postfix(expression,i));
        if (temp<0) {
            temp=-temp;
        }

        if (temp>answer) {
            answer=temp;
        }
    }

    return answer;
}