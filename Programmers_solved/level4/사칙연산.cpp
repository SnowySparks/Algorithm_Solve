#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define mins -20000000
#define maxs 200000000

int dp_max[101][101];
int dp_min[101][101];

int result(int a,int b,const string &operand) {
    if (operand == "-") return a-b;
    else return a+b;
}

int solution(vector<string> arr)
{
    int length = arr.size() /2+1;

    for (int i = 0 ; i < length ; i++) {
        fill(dp_max[i],dp_max[i]+length,0);
        fill(dp_min[i],dp_min[i]+length,0);
    }

    for (int i = 0 ; i <arr.size(); i++) {
        if (i%2==0) {dp_max[i/2][i/2] = stoi(arr[i]);
            dp_min[i/2][i/2] = dp_max[i/2][i/2];        
            }
    }

    for (int i = 1 ; i <length; i++) {//몇 개씩 묶는가-1
        for (int j = 0; j+i <length; j++) { //시작위치
            dp_max[j][j+i] = mins;
            dp_min[j][j+i] = maxs;
            for (int k = j; k<i+j ; k++) {
                if (arr[k*2+1] == "+") {
                dp_max[j][i+j] = max(dp_max[j][i+j] , result(dp_max[j][k],dp_max[k+1][i+j],arr[k*2+1])); 
                dp_min[j][i+j] = min(dp_min[j][i+j] , result(dp_min[j][k],dp_min[k+1][i+j],arr[k*2+1])); 
                }
                else {
                dp_max[j][i+j] = max(dp_max[j][i+j] , result(dp_max[j][k],dp_min[k+1][i+j],arr[k*2+1])); 
                dp_min[j][i+j] = min(dp_min[j][i+j] , result(dp_min[j][k],dp_max[k+1][i+j],arr[k*2+1]));  
                }
            }
        }
    }


    return dp_max[0][length-1];
}