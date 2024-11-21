//https://programmers.co.kr/learn/courses/30/lessons/42842
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    set<int> length;
    int a=(int)sqrt(yellow);
    
    for (int i=1;i<=a;i++) {
        if (yellow%i==0) {
            length.insert(i);
        }
    }
    
    int le,s;
    
    for (int i:length) {
        le=i;
        s=yellow/i;
        
        if ((le*2 + (s+2)*2)==brown) {
            break;
        }
    }
    
    if (le<s) {
        int temp=s;
        s=le;
        le=temp;
    }
    
    answer.push_back(le+2);
    answer.push_back(s+2);
    
    return answer;
    
}