#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s; s = "0" + s;
    int l = s.size()-1; // 1 ~ l 
    vector<vector<bool> > p(l+1, vector<bool>(l+1,false)); 
    vector<int> dp(l+1,2501); // 1 ~ i번째 문자열까지 파악했을 때 그 해당 구간 내 최소 분열 개수

    for (int i = 1; i <= l ; i++) p[i][i] = true;
    for (int i = 1; i < l ; i ++) if (s[i]==s[i+1]) p[i][i+1]= true;

    for(int aidx = 2; aidx < l ; aidx++) {
        for (int st = 1; st+aidx <= l ; st++) {
            if (s[st]==s[st+aidx] && p[st+1][st+aidx-1]) p[st][st+aidx]=true;
        }
    }

    dp[0] =0; dp[1]=1;
    for (int i = 2; i <= l ;i++) {
        for (int st = 1; st <=i;st++) {
            if (p[st][i]) dp[i]=min(dp[i],dp[st-1]+1);
        }
    }
    cout << dp[l];
    return 0;
}