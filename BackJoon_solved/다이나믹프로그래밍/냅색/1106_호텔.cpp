#include <iostream>
#include <algorithm>
#define f(a,b,c) for (int a = b; a <= c; a++)
using namespace std;
const int inf = 1E6+1;
int C, N;
pair<int, int> dt[21];
int dp[21][inf]; // i번째 도시, Cost = 최대 인원

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> C >> N;
    f(i,1,N) cin >> dt[i].first >> dt[i].second;
    sort(dt+1, dt+1+N);
    f(i,1,N) {
        for(int k = 1; k<inf ;k++) {
           if(k >= dt[i].first) dp[i][k] = max(dp[i-1][k], dp[i][k - dt[i].first] + dt[i].second);
           else dp[i][k] = dp[i-1][k];
        }
    }
    f(i,1,inf-1) {
        if (dp[N][i] >= C) {
            cout << i; break;
        }
    } return 0;
}