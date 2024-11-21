#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int,int> > dt[26]; //loc, ans
    int t,lp;
    for (int i = 0 ; i < s.size(); i++) {
        t = s[i] - 'a';
        if (dt[t].size() == 0) {
            dt[t].push_back({i,-1});
        }
        else {
            lp = dt[t].size();
            dt[t].push_back({i, i-dt[t][ lp -1].first});
        }
    }
    vector< pair<int,int> > temp;
    for (int i = 0 ; i <26;i++) {
        if (dt[i].size() == 0) continue;
        for (pair<int, int> p : dt[i]) {
            temp.push_back(p);
        }
    }
    sort(temp.begin(), temp.end());
    for (pair<int, int > a  : temp) {
        answer.push_back(a.second);
    }
    return answer;
}