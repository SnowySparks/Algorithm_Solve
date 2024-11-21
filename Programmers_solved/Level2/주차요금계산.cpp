#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, int> table; //차량번호 , 들어간시간 ( -1 이면 없는 것 취급하기)
    map<int, int> result; //차량번호  누적시간

    int time , num , money , dur;
    for (string s : records) {
        time = stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
        num = stoi(s.substr(6,4));
        if (*(s.end()-1) == 'N') {//들어간 경우
            table[num] = time;
            if (result.find(num) == result.end()) result[num] = 0;
        }
        else {// 나간경우 누적합
            dur = time - table[num];
            result[num] += dur;
            table[num] = (-1);
        }
    }
    //들어가고 안나간 경우 전부 전산 처리 1440 -1
    for (auto e : table) {
        if (e.second != (-1)) {
            result[e.first] += (1440 -1 - table[e.first]);
        }
    }
    //돈계산
    for (auto e : result) {
        if (e.second <= fees[0]) answer.push_back(fees[1]);
        else {
            money = ((e.second - fees[0]) /fees[2] + ((e.second -fees[0])%fees[2] != 0 ? 1 : 0)) * fees[3] + fees[1];
            answer.push_back(money);
        }
    }
    return answer;
}