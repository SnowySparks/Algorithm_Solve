//https://programmers.co.kr/learn/courses/30/lessons/12909
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int c=0;
    for (auto k : s) {
        if (k=='(') {
            c++;
        }
        else if (k==')') {
            c--;
        }
        
        if (c<0) {
            break;
        }
    }
    
    return (c==0)?true:false;
        
}