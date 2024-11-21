#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 20000000
using namespace std;

int work[20][20];
int dp[1 << 20];
int N; 
int dfs (int cur, int states) {
    //몇명째 완료된 상태인가? , 어느직업이 픽되어졌는가?
    if (states == (1<<N) -1 ) return 0;
    int &ret = dp[states]; //이미 도달한 값 ->즉각종료
    if (ret != -1) return ret;
    ret = inf;

    for (int i = 0; i < N; i++) {
        if (!(states & (1<<i))) {
            ret = min (ret, dfs(cur+1, states | (1<<i)) + work[cur][i]);
        }
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (int i = 0 ; i< N ; i++) {
        for (int j = 0; j < N; j++) {
            cin >> work[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout <<dfs(0,0); return 0;
}