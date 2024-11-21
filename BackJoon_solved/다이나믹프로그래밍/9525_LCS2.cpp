#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int dp[1001][1001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string inp1, inp2; cin >> inp1 >> inp2;
    for (int i = 1 ; i <= inp1.size(); i++) {
        for (int j = 1 ; j <= inp2.size(); j++) {
            if (inp1[i-1] == inp2[j-1]) {dp[i][j] = dp[i-1][j-1]+1;}
            else { dp[i][j] = max( dp[i][j-1], dp[i-1][j]);}
        }
    }
    int r = inp1.size(), c = inp2.size();
    int ans = dp[r][c];
    stack<int> st;
    while (dp[r][c] != 0) {
        if (dp[r][c] == dp[r][c-1]) c--;
        else if (dp[r][c] == dp[r-1][c]) r--;
        else if (dp[r][c] -1 == dp[r-1][c-1]) {
            st.push(r);
            r--; c--;
        }
    }
    cout << ans <<'\n';
    while (!st.empty()) {
        cout << inp1[st.top()-1];
        st.pop();
    }
    return 0;
}