#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool dp[2501][2501];
//dp [x][y] -> x번째부터 y번째까지 수열이 팰린트룸인가?
// [x][y] 만족한다는건 [x+1][y-1]도 만족해야 한다는 것이다.
using namespace std;
int solution(string s)
{
    int n = s.size();
    int answer=0;
    s=" "+s;
    
    for (int i = 1; i <= n; i++) {
        dp[i][i] = true;
    }
    
    for (int i = 1 ; i<=n-1 ; i++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
        }
    }
    
    for (int i = n-1 ; i>=1; i--) {
        for (int j = i; j<=n;j++) {
            if (s[j]==s[i] && dp[i+1][j-1] == true) 
                dp[i][j] = true;
        }
    }
    
    for (int i=1;i<=n;i++) {
        for (int j = i ; j<=n;j++) {
            if (dp[i][j] == true && answer < (j-i+1))
                answer = j-i+1;
        }
    }
    return answer;
    
    

}