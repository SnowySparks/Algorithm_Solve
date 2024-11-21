//https://programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> split(string s,char del) {
    vector<string> result;
    stringstream ss(s);
    string temp;
    
    while (getline(ss,temp,del)) {
        result.push_back(temp);
    }
    return result;
}

vector<string> solution(vector<string> record) {
    map<string,string> data;
    vector<string> answer;
    vector<string> sp;
    for (string s : record) {
        if (s[0]=='E'||s[0]=='C') {
            sp=split(s,' ');
            data[sp[1]]=sp[2];
            sp.clear();
        }
    }
    
    for (string s : record) {
        if (s[0]=='E') {
            sp=split(s,' ');
            answer.push_back(data.find(sp[1])->second+"님이 들어왔습니다.");
            sp.clear();
        }
        else if (s[0]=='L') {
            sp=split(s,' ');
            answer.push_back(data.find(sp[1])->second+"님이 나갔습니다.");
            sp.clear();
        }
    }
    
    return answer;
}