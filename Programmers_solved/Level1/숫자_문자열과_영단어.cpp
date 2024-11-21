//https://programmers.co.kr/learn/courses/30/lessons/81301

#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

vector<string> numbers ={"zero","one","two","three","four","five","six","seven","eight","nine"};

vector<string> n={"0","1","2","3","4","5","6","7","8","9"};

int solution(string s) {
    int a=0;
    string::iterator iter=s.begin();
    while(iter!=s.end()) {
        if (isalpha(*iter)!=0) {
            for (int i=0;i<10;i++) {
                if (s.find(numbers[i])!=string::npos) {
                    s.replace(s.find(numbers[i]),numbers[i].length(),n[i]);
                    break; }
            }
        }
        else {
            iter++;
        }
    }
    cout<<s<<endl;
    
    for (auto k=s.begin();k!=s.end();k++) {
        a*=10;
        a+=(*k)-'0';
    }
    return a;
}