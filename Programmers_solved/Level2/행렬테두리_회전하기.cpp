//https://programmers.co.kr/learn/courses/30/lessons/77485
#include <string>
#include <vector>
#include <iostream>

using namespace std;


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
   vector<vector<int>> ary;
    vector<int> answer;
    
for (int i=0;i<rows;i++) {
        vector<int> p;
        for (int k=0;k<columns;k++) {
            p.push_back(i*columns+(k+1));
        }
        ary.push_back(p);
        p.clear();
    }
    int min=10000;
    int save=0;
    
    for (vector<int> query : queries) {
    int x1=query[0]-1;
    int y1=query[1]-1;
    int x2=query[2]-1;
    int y2=query[3]-1;
    
    int min=10000;
    int save=ary[x1][y1];
    
    for (int i=x1;i<x2;i++) {
        ary[i][y1]=ary[i+1][y1];
        if (min>ary[i][y1]) {
            min=ary[i][y1];
        }
    }
    
    for (int k=y1;k<y2;k++) {
        ary[x2][k]=ary[x2][k+1];
        if (min>ary[x2][k]) {
            min=ary[x2][k];
        }
    }
    
    for (int g=x2;g>x1;g--) {
        ary[g][y2]=ary[g-1][y2];
        if (min>ary[g][y2]) {
            min=ary[g][y2];
        }
    }
    
    for (int a=y2;a>y1;a--) {
        ary[x1][a]=ary[x1][a-1];
        if (min>ary[x1][a]) {
            min=ary[x1][a];
        }
    }

    ary[x1][y1+1]=save;
    
    if (min>save) {
        min=save;
    }
        
    answer.push_back(min);
}
    
    
    
    
    
    return answer;   
}