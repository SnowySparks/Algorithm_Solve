#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1000];
string ans = "";
int check(const string &a) {
    // 오 group == 2
    if ( a.size() == 2 && a[0] == a[1]) return 2;
    if ( a.size() == 3 && a[0] == a[1] && a[1] ==a[2]) return 2;
    //강 == 1
    if (a.size() == 3 && ( a[0]==a[1] || a[1] == a[2] || a[0] == a[2]) ) return 1;
    return 0;
}

string inp;
int n;

void back_track(string a, int now, int score) { //현재까지의 누적 string , 현재 idx위치, 누적 점수
    if (now == n-1) {
        if (score > dp[n]) {
            score = dp[n];
            ans = a;
        }
        if (score == dp[n] && ans > a) ans = a;
        return;
    }
    if (now >= n || now == n-2) return;
    int res;
    string temp = "";
    if (now+2 < n) {
        temp = inp.substr(now+1,2);

        res = check(temp);
        if (score + res > dp[now+2]) {
            dp[now+2] = score + res;
            back_track(a+"-"+temp,now+2,score+res);
        } 
    }
    if (now+3 < n) {
        temp.push_back(inp[now+3]);
        res = check(temp);
        if (score + res > dp[now+3]) {
            dp[now+3] = score + res;
            back_track(a+"-"+temp,now+3,score+res);
        } 
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> inp; n =inp.size();
    for (int i = 0 ; i <= n ;i++) dp[i] = -1;
    back_track("",-1,0);
    cout << ans.substr(1,ans.size()-1);
    return 0;

}