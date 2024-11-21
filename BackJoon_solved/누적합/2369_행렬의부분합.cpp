#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//나머지 합 테크닉 이용 -> 다만 열은 그대로, 행은 양 끝단 위치를 골른 뒤 그 사이의 합을 이용
//마치 하나의 벡터같이 처리가 됨
int dt[257][257];
int sum[257][257]; //오로지 위에서 아래쪽으로만 연산
int temp[257];//양 끝단 행 저정, 인덱스는 열
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long answer = 0;
    int N,M,Kp; cin >> N >> M >> Kp;
    for (int i = 1 ; i <= N ; i++) {
        for (int j = 1; j<=M ; j++) {
            cin >>dt[i][j];
            sum[i][j] = sum[i-1][j] + dt[i][j];
        }
    }
    unordered_map<int,int> rest; //나머지 저장하는 곳
    for (int i = 1 ; i<= N ; i++) {
        for (int j = i ; j <= N ; j++) {
            //행 i, j 양끝단 선택,
            for (int k = 1 ; k <= M ; k++) {
                //열 -> 마치 나머지 합 파트처럼 
                temp[k] =(temp[k-1] + (sum[j][k] - sum[i-1][k]))%Kp;
                rest[temp[k]]++; //나머지 갱신
            }
            answer += rest[0]; //같은 나머지 2개 빼는 경우 전체 + 나머지 0 하나 그 자체인 경우
            for (auto e : rest) {   
                answer += ((e.second)*(e.second-1)/2);
            }
            rest.clear();
        }
    }
    cout <<answer; return 0;
}