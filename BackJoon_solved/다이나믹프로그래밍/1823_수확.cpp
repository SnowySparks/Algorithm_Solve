#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[2002][2002]; //왼쪾에서 l+1만큼 오른쪽에서 r-1 만큼 갰을 경우 최대값 저장
int arr[2002];
//가장 큰 이득이 되는 경우에 최대 가치를 부여하고 차례차례 가치값을 낮춰 더하는 방식
int dfs (int l, int r, int time) {
    if (l >r) return 0; //존재하지 않는 경우
    if (dp[l][r] != -1) return dp[l][r];//이미있음
    dp[l][r] = max( arr[l]*time + dfs(l+1,r,time+1), arr[r]*time + dfs(l,r-1,time+1));
    return dp[l][r];
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i = 1 ; i <= N ; i++) { cin >> arr[i];}
    for (int i = 0 ; i <= N ; i++) { 
        for (int j = 0 ; j <= N ; j++) {
            dp[i][j] = -1;
        }
    }
    cout << dfs(1,N,1);
    return 0;
}