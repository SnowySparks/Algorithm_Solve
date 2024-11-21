#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dp[5001];
int main(void) {
    string inp; cin >> inp;
    inp = "0" + inp;
    int N = inp.size();
    
    if (inp[1] == '0') {cout << '0'; return 0; }
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2 ; i <= N ; i++) {
        if (inp[i] !='0') dp[i] += dp[i-1];
        int v = stoi(inp.substr(i-1,2));
        if (v>= 10 && v <= 26) {
            dp[i] += dp[i-2];
        }
        dp[i]%=1000000;
    }
    cout << dp[N];
    return 0;
}