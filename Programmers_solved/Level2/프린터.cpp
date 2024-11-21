//https://programmers.co.kr/learn/courses/30/lessons/42587
//큐 안쓰고 플기. - 다만 효율성을 고려하면 큐 사용하는 것이 유리.
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer=0;
    int loc=location;
    int max;
    int temp;
    while (true) {
    if (priorities.size()>1) {
    max=*max_element(priorities.begin()+1,priorities.end()); }
    else {
        max=priorities[0];
    }
    
    if (max>priorities.front()&&priorities.size()>1) {
         temp=priorities.front();
        priorities.erase(priorities.begin());
        priorities.push_back(temp);
        
        if (loc!=0) {
            loc--;
        }
        else {
            loc=priorities.size()-1;
        }
    }
    else {
        if (loc==0) {
            answer++;
            break;
        }
        loc--;
        priorities.erase(priorities.begin());
        answer++;
    }
    }

    return answer;
}