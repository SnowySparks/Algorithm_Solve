#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool comp(const string &a,const string &b) {
    if (a.length() == b.length()) {
         for (int i = 0; i < a.size(); i++) {
            if ( a[i]== b[i]) continue;
            return a[i] - '0' > b[i] - '0';
        }       
    }
    return a.length() >= b.length();
}

bool isallzero(const string &a) {
    if (a.size()==0) return false;
    for (auto e : a) {
        if (e != '0') return false;
    } return true;
}

int money[10];
string dp[51];

int usm(const string &a) {
    if (a.size() == 0) return 0;
    int sum = 0;
    for (auto e : a) {
        sum+= money[e - '0'];
    } return sum;
}
int main(void) {
    int N; cin >> N;
    for (int i = 0; i < N ; i++) cin >> money[i];
    int max_money = *max_element(money+1,money+10);
    int M ; cin >> M;
    for (int i = 1 ; i <= M ; i++) {
        dp[i] = dp[i-1];
        for (int j = N-1 ; j >= 0 ; j--) {
            if ( i - money[j] >= 0 ) {
                string st1 = dp[ i - money[j]] + to_string(j);
                string st2 = to_string(j) + dp[i - money[j]];
                if (isallzero(st1) && M - i < max_money) {
                    st1 = "0";
                }
                if (isallzero(st2) && M - i < max_money) {
                    st2 = "0";
                }
                string res = comp(st1,st2) ? st1 : st2;
                dp[i] = comp(dp[i], res) ? dp[i] : res;
            }
        }
    }
    cout << dp[M];
    return 0;
 }