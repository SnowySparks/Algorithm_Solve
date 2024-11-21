#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

#define inf 2000000000
using namespace std;

int file[501], sum[501]; //sum : 1 ~ x까지 합값
int dp[501][501]; //dp[i][k] : i 번째에서 k번째 까지 파일 합들 중 가장 최소값

int main (void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int k = 0, temp;
    while (N--) {
        cin >> k;

        //file 입력 및 sum값 갱신
        for (int i = 1; i<= k ; i++) {
            cin >> file[i];
            sum[i] = sum[i-1] + file[i];
        }

        //i 부터 k까의 파일들 중에서, i~p의 합, p+1~k까지의 합 이 둘의 합이 가장 최소가 되는 곳을 찾는 방법
        for (int i = 1; i <= k; i ++) {
            for (int j = 1 ; j <= k - i; j++) { 
                dp[j][j+i] = inf;
                for (int p = j ; p <i+j ; p ++) {
                    dp[j][i+j] = min (dp[j][i+j], dp[j][p]+dp[p+1][i+j]+sum[i+j]-sum[j-1]);
                }
            }
        }
        cout << dp[1][k]<<'\n';
    }
    return 0;    
}