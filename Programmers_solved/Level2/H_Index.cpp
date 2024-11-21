//https://programmers.co.kr/learn/courses/30/lessons/42747
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int size=citations.size();
    int answers=0;
    sort(citations.begin(),citations.end());
    
    for (int i=0;i<size;i++) {
       if (citations[i]>=(size-i)) {
           answers=size-i;
           break;
       }
    }
    return answers;
}