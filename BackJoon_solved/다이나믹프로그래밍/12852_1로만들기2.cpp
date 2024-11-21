#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000001];
int dp_loc[1000001];

int main(void) {
    ios_base::sync_with_stdio(false) ; cin.tie(NULL); cout.tie(NULL);
    int x; cin >> x;

    for (int i = 2 ; i <= x ; i++) {
        dp[i] = dp[i-1] + 1;
        dp_loc[i] = i-1;
        if (i%2 == 0) dp[i] = min(dp[i] , dp[i/2] +1);
        if (i%3 ==0) dp[i] = min(dp[i] ,dp[i/3] +1); }

    cout << dp[x] << '\n';

    int loc= x; //역추척
    while (loc!=1) {
        cout << loc << ' ';
        //n 에서 다음 최소로 갈 때, 그 홧수차이는 -1 이라는 것을 이용. 
        if (dp[loc] == dp[loc-1] +1) loc--;
        else if (loc%2==0 &&dp[loc] == dp[loc/2] +1) loc/=2;
        else if (loc%3==0 &&dp[loc] == dp[loc/3]+1) loc/=3;
    }
    cout << 1;

    return 0;
}