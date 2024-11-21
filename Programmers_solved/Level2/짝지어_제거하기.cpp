//https://programmers.co.kr/learn/courses/30/lessons/12973
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> p;
    
    for (char c:s) {
        if (p.empty()) {
            p.push(c);
        }
        else if (p.top()==c) {
            p.pop();
        }
        else {
            p.push(c);
        }
    }
    
    return p.size()?0:1;
    
}