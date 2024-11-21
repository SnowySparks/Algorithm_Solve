#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {
    vector<int> answer;
    int dp[100001][2]; //total , index

    for (int i = 0 ; i <= target ; i++) {
        // 1~20 or 50 싱글이나 볼 1회
        if (i<=20 || i == 50) {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        //60이하 3의배수 - 트리플 1회
        else if (i <= 60 && i%3 ==0) {
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        //40이하 2의배수 - 더블 1회
        else if (i <= 40 && i%2 == 0) {
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        //50 초과 ~ 70이하 -> 싱글 볼 한번씩
        else if (i > 50 && i<= 70) {
            dp[i][0] = 2;
            dp[i][1] = 2;
        }
        //싱글 2번
        else if (i < 40) {
            dp[i][0] = 2;
            dp[i][1] = 2;
        }
        //트리플 or 더블 1회 + 싱글 1회
        else if ( i < 70) {
            dp[i][0] = 2;
            dp[i][1] = 1;
        }
        //70 넘는 경우 dp[i-50][0] dp[i-60][0]비교 
        else {
            if (dp[i-50][0] <= dp[i-60][0]) {
                dp[i][0] = dp[i-50][0]+1;
                dp[i][1] = dp[i-50][1]+1;
            }
            else {
                dp[i][0] = dp[i-60][0] + 1;
                dp[i][1] = dp[i-60][1];
            }
        } 
    }
    answer.push_back(dp[target][0]);
    answer.push_back(dp[target][1]);

    return answer;
}