#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int sale[4] = {40,30,20,10};
vector<int> table; //이모티콘 각 할인율
vector<int> ans = {0,0};

void calc(const vector<vector<int> >  & users,const vector<int> & emot) { 
    int user_count = users.size();
    int emoticonplus=0;
    int calc_money = 0;
    int temp;
    for (int i = 0 ; i < user_count ; i++) {
        temp = 0;
        for (int j = 0 ; j < emot.size(); j++) {
            if (table[j] >= users[i][0]) { //할인율이 각 유저 조건 이상인 경우 전부 더함
                temp+= (emot[j] / 100 * (100-table[j]));
            }
        }
        if (temp >= users[i][1]) {
            emoticonplus++;
        }
        else {
            calc_money+=temp;
        }
    }
    if (ans[0] < emoticonplus) {
        ans[0] = emoticonplus; ans[1] = calc_money;
    }
    else if (ans[0] == emoticonplus && ans[1]<calc_money)  {
        ans[1] = calc_money;
    }
}

void dfs (int cnt, int N, int M,const vector< vector<int> > &user,const vector<int> & emoti) {
    if (cnt == M) { calc(user,emoti); return;}
    for (int i = 0 ; i < N ; i++) {
        table.push_back(sale[i]);
        dfs(cnt+1, N, M,user,emoti);
        table.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    dfs(0,4,emoticons.size(),users,emoticons);
    answer.push_back(ans[0]); answer.push_back(ans[1]);
    return answer;
}