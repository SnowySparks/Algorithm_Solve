#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[200][200];
pair<int, int> dt[200];
int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    int n = matrix_sizes.size();

    for (int i = 1 ; i < n ; i++) {
        for (int j = 0 ; i+j < n ; j++) {
            dp[j][i+j] = 987654321;
            for (int k = j ; k < i+j ; k++) {
                dp[j][i+j] = min ( dp[j][i+j] , dp[j][k] + dp[k+1][j+i] + matrix_sizes[j][0] * matrix_sizes[k][1] * matrix_sizes[j+i][1]);\
            }
        }
    }

    return dp[0][n-1];
}