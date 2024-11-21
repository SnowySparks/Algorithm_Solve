//https://programmers.co.kr/learn/courses/30/lessons/77884

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int counter(int nums) {
    int count=0;
    int a=(int)sqrt(nums);
    
    for (int i=1;i<=a;i++) {
        if (nums%i==0) {
            if (nums/i==i) {
                count++;
            }
            else {
                count+=2;
            }
        }
    }
    return count;
}

int solution(int left, int right) {
    int answer=0;
    vector<int> a;
    
    for (int i=left;i<=right;i++) {
        a.push_back(i);
    }
    
    for (int d : a) {
        if (counter(d)%2==0) {
            answer+=d;
        }
        else {
            answer-=d;
        }
    }
    
    return answer;
    
    
}