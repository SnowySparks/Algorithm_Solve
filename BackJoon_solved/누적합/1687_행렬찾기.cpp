#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string inp[334];
int dp[335][335];
int sum[334];
//테크닉 : 나머지 합
//상위테크닉 : 행렬의 부분합
int answer = 0;
int main(void) {
    int N, M ; cin >> N >> M;
    for (int i = 1; i <= N ; i++) {
        cin >> inp[i];
        for (int j = 0 ; j < M ; j++) {
            if (inp[i][j] == '0') dp[i][j+1] = dp[i-1][j+1] +1;
        }
    }
    int save_row; int start; int end; bool check;
    for (int i = 1 ; i <= N ; i++) {
        for (int j = i  ; j <= N ; j++) {
            start=0; end=0; save_row = (j-i+1); check =false; //맨처음 처번째 열 높이, 오직 이것만 신경씀
            for (int k = 1 ; k <= M+1 ; k++) {
                sum[k] = dp[j][k] - dp[i-1][k];
                if (sum[k-1] != sum[k] && sum[k] == save_row) {start=k; end=k; check =true;}
                if (sum[k] == save_row) end = k;
                else if (sum[k-1] != sum[k] && sum[k]!=save_row) {
                    if (check) answer = max(answer, save_row*(end-start+1));
                    check = false;
                }
            }
        }
    }
    cout << answer; 
    return 0;
}