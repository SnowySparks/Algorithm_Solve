#include <iostream>
#include <cstring>
using namespace std;
int mod = 2552;
int dp[1002][1002];
int minima_block[1001][2]; //  [가장 start로부터 가까운 위치 값] [ 왼쪽으로부터 = 0 / 아래로부터 = 1 ] 
const int inf = 1e9+1;
int w,h,k;
typedef struct _io {
    int x1, y1, x2, y2;
    bool operator<(const struct _io &a) const {
        if (y1 != a.y1) return y1 < a.y1;
        if (x1 != a.x1) return x1 < a.x1;
        if (y2 != a.y2) return y2 < a.y2;
        if (x2 != a.x2) return x2 < a.x2;
    }
} io;

typedef struct cmp {
    bool operator()(const io &a, const io &b) {
        
    }
}

int cal(int x1, int y1, int x2, int y2) { //from x1,y1 to x2,y2
    if (x1 > x2 || y1 > x2) return 0;
    return dp[x2-x1][y2-y1];
}

int pt_to_pt(int x1, int y1, int x2, int y2) {
    return (cal(0,0,x1,y1) * cal(x2,y2,w,h)) % mod;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // cal maps
    for (int i = 0 ; i <= 1001; i++) {
        dp[i][0] = 1; dp[0][i] = 1;
    }
    for (int i = 1; i <= 1001; i++) {
        for (int j = 1; j <= 1001 ; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
        }
    }

    int t; cin >> t;
    while(t--) {
        cin >> w >> h >> k;
        for (int i = 0 ; i <= h; i++) {
            minima_block[i][0] = inf; minima_block[i][1] = inf;
        }
        
    }
    return 0;
}