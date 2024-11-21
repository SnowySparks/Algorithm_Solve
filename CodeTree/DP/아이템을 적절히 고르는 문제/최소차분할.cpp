#include <iostream>
#include <cstring>
#include <vector>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
const int inf =1e9+7;
const int max_val = 1e5;
int n;
int arr[101];
bool dp[101][max_val+1];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int total = 0;
    f(i,1,n+1) cin >> arr[i];
    f(i,1,n+1) total += arr[i];
    dp[0][0] = true;

    f(i, 1, n+1) {
        f(j, 0, total+1) {
            if (dp[i-1][j]) {
                dp[i][j + arr[i]] = true;
                dp[i][abs(j - arr[i])] = true;
            }
        }
    }
    f(i, 0, total) {
        if (dp[n][i]) {
            cout << i;
            break;
        }
    }
    return 0;
}

// 내풀이 : dp[i][j], i까지 보았을 때 무게 차이가 j이 가능한가 불가능한가
// 다른사람풀이 , dp[i], 한쪽만 수를 넣었을 때 가능한 부분집합의 총합들을 두고
// m - i (if dp[i]) 의 최소값들을 찾기