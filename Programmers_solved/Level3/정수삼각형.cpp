#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int dp[500][500];
    int a = triangle.size();

        dp[0][0]=triangle[0][0];

    for (int i = 1; i < a; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j==0) {
                dp[i][0]=dp[i-1][0]+triangle[i][0];
            }
            else if (j==i) {
                dp[i][j]=dp[i-1][j-1]+triangle[i][j];
            }
            else {
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
        }
    }

    return *max_element(dp[a-1],dp[a-1]+a);
}
