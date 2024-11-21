//https://programmers.co.kr/learn/courses/30/lessons/42586
//스택/큐 사용을 의도한 문제지만 그 클래스 사용 안하고 풀기

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> complete;
    int count;
    int size=progresses.size();
    for (int i=0;i<size;i++) {
        count=(100-progresses.at(i))/speeds.at(i);
        if ((100-progresses.at(i))%speeds.at(i) != 0) {
            count++;
        }
        complete.push_back(count);
    }
    int standard=complete.front();
    count=0;
    
    for (int i=0;i<size;i++) {
        if (standard>=complete.at(i)) {
            count++;
        }
        
        else {
            answer.push_back(count);
            count=1;
            standard=complete.at(i);
        }
    
    }
    
    answer.push_back(count);
    
    return answer;
}