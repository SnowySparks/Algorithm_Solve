//https://programmers.co.kr/learn/courses/30/lessons/1835
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int abs(int a) {
    if (a<0) {
        return (-1)*(a);
    }
    return a;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    string s="ACFJMNRT";
    int count=0;
    int result=0;
    do {
        result=0;
        for (int i=0;i<n;i++) {
            if (data[i][3]=='>'&&abs((int) (s.find(data[i][0])-s.find(data[i][2])))-1>(data[i][4]-'0')) {
                result++;
            }
            if (data[i][3]=='<'&&abs((int) (s.find(data[i][0])-s.find(data[i][2])))-1<(data[i][4]-'0')) {
                result++;
            }
            if (data[i][3]=='='&&abs((int) (s.find(data[i][0])-s.find(data[i][2])))-1==(data[i][4]-'0')) {
                result++;
            }
        }
        if (result==n) {
            count++;
        }
    } while (next_permutation(s.begin(),s.end()));
    return count;
}