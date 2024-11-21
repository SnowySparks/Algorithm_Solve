#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define f(a,b,c) for(int a=b;a<=c;a++)
int n;
const int inf = 1e9+1;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> arr(n+1,0);
    f(i,1,n) cin >> arr[i];
    vector<vector<int> > dp(n+1,vector<int>(4,inf)); //dp[i][j] , i = idx (1 ~n), j : fix count : 0 ~3
    //dp : i번째 인덱스에서 j번 수정했을꼉우에 i인덱스가 가질 수 있는 최소값

    dp[1][0] = arr[1]; dp[1][1] =dp[1][2] =dp[1][3] = 1;
    f(i,2,n) {
        if (dp[i-1][0] <= arr[i]) dp[i][0] = arr[i]; // 미수정 -> 무조건 올림차순까지만 적용...
        else dp[i][0] = inf; //아니면 그냥 불가능
        f(k,1,3) dp[i][k] = min(dp[i-1][k-1], (dp[i-1][k] <= arr[i] ? arr[i]:inf));
        // 수정 . [i-1][k-1] 값을 가져오면 되긴 됨.
    }

    if (min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3])) == inf) cout <<"NO";
    else {
        int fix_mcnt = 0, mval = inf;
        f(i,0,3) {
            if (dp[n][i] < mval) {
                mval = dp[n][i];
                fix_mcnt = i;
            }
        }
        cout<<"YES\n"<<fix_mcnt<<'\n';

        for (int i = n ; i>= 1 && fix_mcnt >= 1 ; i--) {
            if (dp[i-1][fix_mcnt] > arr[i] || dp[i-1][fix_mcnt-1]<arr[i])  {
                cout << i << ' ' << dp[i][fix_mcnt--] <<'\n';
            }
        }
    }
    return 0;
}