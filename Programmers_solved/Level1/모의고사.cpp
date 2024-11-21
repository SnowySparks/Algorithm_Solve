//https://programmers.co.kr/learn/courses/30/lessons/42840
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int,int> &a1,pair<int,int> &a2) {
    if (a1.second==a2.second) {
        return a2.first>a1.first;
    }
    return a1.second>a2.second;
}

int counter(vector<int> input,vector<int> answers) {
    int count=0;
    int lc=0,inp_size=input.size(),ans_size=answers.size();

    
    for (int i=0;i<ans_size;i++) {
        if (answers[i]==input[i%inp_size]) {
            count++;
        }
    }
    return count;
}

vector<int> solution(vector<int> answers) {
    vector<vector<int>> input;
    int p;
    vector<int> ans;
    vector<int> a1={1,2,3,4,5};
    vector<int> a2={2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> a3={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<pair<int,int>> temp;
    
    input.push_back(a1);
    input.push_back(a2);
    input.push_back(a3);
    
    for (int i=0;i<3;i++) {
        p=counter(input[i],answers);
        temp.push_back(make_pair(i+1,p));
    }
    sort(temp.begin(),temp.end(),comp);
    
    for (int i=0;i<3;i++) {
        cout<<temp[i].first<<" : "<<temp[i].second<<endl;
    }
    
    ans.push_back(temp[0].first);
    if (temp[1].second==temp[0].second) {
        ans.push_back(temp[1].first);
        if (temp[2].second==temp[0].second) {
            ans.push_back(temp[2].first);
        }
    }
    
    return ans;
    
}