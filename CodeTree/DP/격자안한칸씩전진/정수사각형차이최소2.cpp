#include <iostream>
#include <cstring>
#include <queue>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
const int inf =1e9+7;
int n;
int arr[100][100];
int tmp[100][100];
int dp[100][100];

// thresh : 모든 블럭이 최소 thresh 이상값이라 가정, 아닌 블럭은 막아두기
void init(int thresh){
    f(i, 0, n) f(j, 0, n) {
        tmp[i][j] = (arr[i][j] < thresh ? inf : arr[i][j]);
    }
    dp[0][0] = arr[0][0];

    f(i, 1, n) {
        dp[0][i] = max(dp[0][i-1], tmp[0][i]);
        dp[i][0] = max(dp[i-1][0], tmp[i][0]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    f(i, 0, n) f(j, 0, n) cin >> arr[i][j];
    int Max_low = arr[0][0];
    int l = 0, r = Max_low;
    int ans = 101;
    while (l <= r) {
        int mid = (l + r) >> 1;
        init(mid);

        f(i, 1, n) {
            f(j, 1, n) {
                dp[i][j] = max(tmp[i][j], min(dp[i-1][j], dp[i][j-1]));
            }
        }

        if (dp[n-1][n-1] == inf) {
            r = mid - 1;
        }
        else {
            ans = min(ans, dp[n-1][n-1] - l);
            l=mid+1;
            // cout << dp[n-1][n-1] - mid <<" <- result" <<'\n';

            // cout << "--" << mid << '\n';
            // f(i, 0, n) {
            //     f(j, 0, n) cout << dp[i][j] << '\t';
            //     cout << '\n';
            // }
            // cout << "--\n";
        }
    }
    
    cout << ans;
}

// 원리 : 완전탐색 + DP
// 최소값은 최소 어떤 값 이상이고, 그 미만인 것들은 block이라고 가정하고 둠
// 그 경계선을 1부터 증가하면서 탐색
// dp는 그럼 (n,n) 까지 가는 모든 경로들의 수 최대값들 중 최소값