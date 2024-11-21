//https://programmers.co.kr/learn/courses/30/lessons/42889
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<double,int>& a, const pair<double,int>& b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector <int> solution(int N, vector <int> stages) {

    vector<int> answer;

    vector<pair<double, int>> fails;

    for (int i = 1; i <=N; i++) {
        double a=0,b=0;
        for (int k=0; k<stages.size(); k++) {
            if (stages[k]==i) {
                a++;
            }
            if (stages[k]>=i) {
                b++;
            }
        }
        if (b!=0) {
            fails.push_back(make_pair(a/b,i));
        }
        else {
            fails.push_back(make_pair(0,i));
        }
    }

    sort(fails.begin(),fails.end(),compare);

    for (auto ab=fails.begin(); ab!=fails.end(); ab++) {
        answer.push_back(ab->second);
    }


    return answer;
}