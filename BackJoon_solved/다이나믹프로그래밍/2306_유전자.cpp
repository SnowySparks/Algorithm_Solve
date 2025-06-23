#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)

string str;
int dp[500][500]; // 길이 i ~ j 까지 염색체 중 "그 염색체"의 최대 길이
bool isKOI(char a,char b){
    if((a=='a'&&b=='t')||(a=='g'&&b=='c'))return true;
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> str;
    int n = str.size();

    // 먼저 2개 (at, gc)
    f(i, 0, n-1) {
        if (str[i] == 'a' && str[i+1] =='t') {
            dp[i][i+1] = 2;
            continue;
        }
        if (str[i] == 'g' && str[i+1] == 'c') {
            dp[i][i+1] = 2;
            continue;
        }
    }

    //확정 탐색 길이 ()
    for (int len = 1; len <= n; len++) {
        for (int start = 0; start < n - len; ++start) {
            if (isKOI(str[start],str[start+len] )) {
                dp[start][start+len] = max(dp[start][start+len], dp[start+1][start+len-1] +2);
            }

            for (int p = start; p < start+len; ++p) {
                dp[start][start+len] = max(dp[start][start+len], dp[start][p]+dp[p+1][start+len]);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}