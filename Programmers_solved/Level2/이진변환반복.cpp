#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    int length=0;
    stack<int> st;
    while (s!="1") {
        answer[1]+=count(s.begin(), s.end(),'0');
        s.erase(remove(s.begin(), s.end(),'0'),s.end());
        length=s.length();
        s.clear();
        answer[0]++;

        while (length!=0) {
            st.push(length%2);
            length=length/2;
        }
        
        while (!st.empty()) {
            if (st.top()==1) {
                s.push_back('1');
            }
            else {
                s.push_back('0');
            }
            st.pop();
        }
    }
    
    return answer;
}