#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define MAX 2147483647
#define MIN 2147483647 *(-1)
using namespace std;

int num[10];
// i ~ j 까지 연산한 결과의 각각 최대, 최소 값들 저장
int dp_max[10][10];
int dp_min[10][10];

int calc (int a, int b, char oper) {
    if (oper == '+') return a + b;
    else if (oper == '-') return a - b;
    else return a * b;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N ; cin >> N;
    string inputd; cin >> inputd;

    for (int i = 0 ; i < N ; i++) {
        if (i%2 == 0) {dp_max[i/2][i/2] = (inputd[i] - '0'); 
        dp_min[i/2][i/2] = dp_max[i/2][i/2]; }
    }
    int len = N/2 +1;

    /*for (int i = 0 ; i < len ; i++) {
        for (int j = 0; j < len ; j++) {
            cout <<"("<<dp_max[i][j]<<","<<dp_min[i][j]<<") ";
        } cout << '\n';
    }*/
    int temp[4] = {0,};
    for (int i = 1 ; i < len ; i++) { // i :(묶어내는 개수 - 1)
        for (int j = 0 ; (i+j) < len ; j++) { //시작위치
            dp_max[j][j+i] = MIN; dp_min[j][i+j] = MAX;

            for (int k = j ; k < (i+j); k++) {
                if (inputd[k*2+1] == '+') {
                    dp_max[j][i+j] = max(dp_max[j][i+j] , (dp_max[j][k] + dp_max[k+1][i+j]));
                    dp_min[j][i+j] = min(dp_min[j][i+j] , (dp_min[j][k] + dp_min[k+1][i+j]));                    
                }
                else if (inputd[k*2+1] == '-') {
                    dp_max[j][i+j] = max(dp_max[j][i+j] , (dp_max[j][k] - dp_min[k+1][i+j]));
                    dp_min[j][i+j] = min(dp_min[j][i+j] , (dp_min[j][k] - dp_max[k+1][i+j]));                    
                }
                else {
                    temp[0] = dp_max[j][k] * dp_max[k+1][i+j];
                    temp[1] = dp_min[j][k] * dp_min[k+1][i+j];
                    temp[2] = dp_min[j][k] * dp_max[k+1][i+j];
                    temp[3] = dp_max[j][k] * dp_min[k+1][i+j];

                    dp_max[j][i+j] = max(dp_max[j][i+j], *max_element(temp,temp+4));
                    dp_min[j][i+j] = min(dp_min[j][i+j], *min_element(temp,temp+4));                    
                }   
            }
        }
    }
    cout << dp_max[0][len-1];

    return 0;
}
