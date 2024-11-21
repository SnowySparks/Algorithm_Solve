#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long S, T; cin >> S >> T;
    if (S == T) { cout << 0; return 0;}
    unordered_map<long long, bool> datas;
    vector<string> answers;
    queue<pair<long long, string> > q;
    q.push({S,""});
    datas[S] = true;  
    while (!q.empty()) {
        long long num = q.front().first;
        string st = q.front().second;
        q.pop();
        if (num == T) { answers.push_back(st); continue; }
        if (num*num <= T && !datas[num*num]) {
            datas[num*num] = true;
            q.push({num*num,st+"*"});
        }
        if (num+num<= T && !datas[num+num]) {
            datas[num+num] = true;
            q.push({num+num,st+"+"});
        }
        if (num>0 &&num/num > 0  && !datas[num/num]) {
            datas[num/num] = true;
            q.push({num/num,st+"/"});
        }
    }
    if (answers.empty()) {cout << -1 ;return 0;}
    else {
        sort(answers.begin(), answers.end());
        cout << answers.front();
        return 0;
    }
}