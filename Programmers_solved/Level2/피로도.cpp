//https://programmers.co.kr/learn/courses/30/lessons/87946

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


bool compare(vector<int> a1,vector<int> a2) {
    return a1[0]>a2[0];
}


int solution(int k, vector<vector<int>> dungeons) {
    int length=dungeons.size();
    int left=k;
    int max=0;
    int count=0;
    sort(dungeons.begin(),dungeons.end());
    
    do {
        left=k;
        count=0;
        for (int i=0;i<length;i++) {
            if (left>=dungeons[i][0]) {
                count++;
                left-=dungeons[i][1];
            }
        }
        if (max<count) {
        max=count; }
    } while (next_permutation(dungeons.begin(),dungeons.end()));
    return max;
}