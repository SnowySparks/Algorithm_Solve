#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

long long dp[360030];// 100시긴 = 6000분 = 360000초

int strtosec(const string & str) {
    int hr = stoi(str.substr(0,2));
    int mr = stoi(str.substr(3,2));
    int sr = stoi(str.substr(6,2));
    return sr + 60 * (mr + hr * 60);
}

string inttostr(int p) {
    string hr = to_string(p/3600);
    if (hr.size() == 1) hr = "0"+hr;
    p%=3600;
    string mr = to_string(p/60);
    if (mr.size() == 1) mr = "0"+mr;
    p%=60;
    string sr = to_string(p);
    if (sr.size() == 1) sr = "0" + sr;
    return hr + ":" + mr + ":" + sr;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int endtime = strtosec(play_time);
    int advtime = strtosec(adv_time);
    fill(dp, dp+endtime+1, 0);
    string temp;
    for (auto e : logs) {
        int st = strtosec(e.substr(0,8));
        int ed = strtosec(e.substr(9));
        dp[st]++; dp[ed]--;
    }
    for (int i = 1 ; i < endtime ; i++) {
        dp[i] += dp[i-1];
    }
    int loc = 0;

    long long sum_play = 0;
    for (int i = 0 ; i < advtime ; i++)  sum_play += dp[i];
    long long max_play = sum_play;
    
    for (int i = advtime ; i < endtime ; i++) { //i : 끝나는시간
        sum_play-=dp[i-advtime];
        sum_play += dp[i]; 

        if (max_play < sum_play) {
            max_play = sum_play;
            loc = i - advtime + 1;
        }

    }

    return inttostr(loc);
}