//https://programmers.co.kr/learn/courses/30/lessons/72410
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string temp;
    transform(new_id.begin(),new_id.end(),new_id.begin(),::tolower);
    regex e("[^-_.a-z0-9]");
    temp=regex_replace(new_id,e,"");
    regex re("[\.]{2,}");
    temp=regex_replace(temp,re,".");
    regex ree("^[.]|[.]$");
    temp=regex_replace(temp,ree,"");
    
    if (temp.size()==0) {
        temp+='a';
    }
    
    if (temp.size()>=16) {
        temp=temp.substr(0,15);
        temp=regex_replace(temp,ree,"");
    }
    else {
        while (temp.size()<=2) {
            temp+=temp[temp.size()-1];
        }
    }
    
    
    cout<<temp<<endl;
    
    return temp;
}