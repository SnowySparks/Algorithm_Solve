//https://programmers.co.kr/learn/courses/30/lessons/77484
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    
    int count=0;
    int zero_count=0;
    for (int i=0;i<6;i++) {
        for (int k=0;k<6;k++) {
            if (lottos[i]!=0 && lottos[i]==win_nums[k]) {
                count++;
                break;
            }
            if (lottos[i]==0) {
                zero_count++;
                break;
            }
        }
    }
    vector<int> answer;
    
    answer.push_back((count>=2)?7-count:6);
    answer.push_back((zero_count+count)>=2?7-(zero_count+count):6);
    int temp;
    if (answer[1]<answer[0]) {
        temp=answer[1];
        answer[1]=answer[0];
        answer[0]=temp;
    }
                     
    return answer;
}