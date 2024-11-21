//https://programmers.co.kr/learn/courses/30/lessons/42626
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int a,b,count=0;
    priority_queue<int,vector<int>,greater<int>> tp;
    for (int i=0;i<scoville.size();i++) {
        tp.push(scoville[i]);
    }
    
    while (tp.size()>1 && tp.top()<K) {
        count++;
        a=tp.top();
        tp.pop();
        b=tp.top();
        tp.pop();
        tp.push(a+2*b);
    }
    return (tp.top()>=K)?count:-1;
    
}