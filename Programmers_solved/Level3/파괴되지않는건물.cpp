#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//누적합
//굳이 일일이 더하지 않고 한번에 처리하는 방식

// (0,0) (3,3) 범위 내 전부 n을 더해야 한다면
// (0,0) = n , (4,4) =n , (0,4) = -n , (4,0) =  -n 을 배치한 다음
// 옆으로 전부 더하고 그리고 아래로 전부 차례대로 누적합을 시킨다 S(n) = S(n-1) + a(n)

int dp_sum[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int row = board.size();
    int col = board[0].size();
    int answer = 0;
    
    for (int i = 0 ; i < row ; i ++) {
        fill(dp_sum[i], dp_sum[i] + col+1,0);
    }
    
    for (vector<int> command : skill) {
        if (command[0] == 1 ) {
            dp_sum[command[1]][command[2]] -= command[5];
            dp_sum[command[3]+1][command[4]+1] -= command[5];
            dp_sum[command[1]][command[4]+1] +=command[5];
            dp_sum[command[3]+1][command[2]] += command[5];
        }
        else {
            dp_sum[command[1]][command[2]] += command[5];
            dp_sum[command[3]+1][command[4]+1] += command[5];
            dp_sum[command[1]][command[4]+1] -=command[5];
            dp_sum[command[3]+1][command[2]] -= command[5];            
        }    
    }
    
    //가로로 전부 더하기
    for (int i = 0 ; i < row ; i++) {
        for (int j = 1 ; j < col ; j ++) {
            dp_sum[i][j] += dp_sum[i][j-1];
        }
    }
    //세로로 전부 더하기
    
    for (int i = 0 ; i < col ; i++) {
        for (int j = 1; j < row ; j++) {
            dp_sum[j][i] += dp_sum[j-1][i];
        }
    }
    
    for (int i = 0 ; i <row ; i++) {
        for (int j = 0 ; j < col ; j ++) {
            if (board[i][j] + dp_sum[i][j] > 0) answer++;
        }
    }
    return answer;
}