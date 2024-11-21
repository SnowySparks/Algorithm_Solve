//https://school.programmers.co.kr/learn/courses/30/lessons/136797?language=cpp
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int loc[10][2] = {{4,2},{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}};

const int steps[10][10] = { //현재 위치 , 다음 이동 번호
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};

int dp[100001][10][10]; //해당 위치 저장값 : 누적된 가중치 , index -> left -> right 순서

int solve (const string &num, int idx=0, int left=4, int right=6) {
    if (idx == num.size()) return 0; //가장 밑바닥의 함수 실행 할 경우에 -1을 0으로 초기화
    int &result = dp[idx][left][right];
    if (result != -1) return result; //이미 저장된 값이 있으면 리턴
    int cur = num[idx] - '0';
    if (left == cur || right == cur) return result = 1+solve(num,idx+1,left,right); //

    return result = min ( solve (num,idx+1,cur,right) + steps[left][cur] , solve (num,idx+1,left,cur) + steps[right][cur] );

}


int solution(string numbers) {
    memset(dp,-1,sizeof(dp)); //-1로 초기화 전부
    return solve(numbers,0,4,6);
}