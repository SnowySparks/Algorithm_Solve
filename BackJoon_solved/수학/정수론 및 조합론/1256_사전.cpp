#include <iostream>
using namespace std;
#define f(a,b,c) for (int a = b; a<=c;a++)
int n, m, k, inf = 1e9;
int dp[101][101];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>> n >> m >> k;

    f(i,1,100) {dp[i][0] = 1; dp[0][i] = 1;}
    f(i,1,100) {
        f(j,1,100) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if (dp[i][j] > inf) dp[i][j]= inf;
        }
    }

    if (dp[n][m] < k) {
        cout << -1; return 0;
    }


    int a= n, z= m;
    for(int i = 0 ; i < n+m ; i++) {
        int a_cnt = dp[a-1][z];
        if (a == 0 ) {
            cout << 'z'; z--;
        }
        else if (z == 0) {
            cout <<'a'; a--;
        }
        else if (a_cnt >= k) {
            cout << 'a';
            a--;
        }
        else {
            cout <<'z';
            z--;
            k-=a_cnt;
        }
        
    }
    return 0;

}