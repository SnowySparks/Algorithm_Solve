//https://programmers.co.kr/learn/courses/30/lessons/1829
#include <vector>
#include <memory.h>
using namespace std;

int count=0;
bool **visited;

bool bfs(int x,int y, int m,int n,vector<vector<int>> picture,int color) {
    if (x<0 || x>=m || y<0 || y>=n || color!=picture[x][y]) {
        return false;
    }
    if (visited[x][y]==false) {
        visited[x][y]=true;
        count++;
        bfs(x+1,y,m,n,picture,color);
        bfs(x-1,y,m,n,picture,color);
        bfs(x,y+1,m,n,picture,color);
        bfs(x,y-1,m,n,picture,color);
        
        return true; 
    }
    return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer={0,-1};
    visited=new bool*[m];
    
    for (int i=0;i<m;i++) {
        visited[i]=new bool[n];
        memset(visited[i],false,sizeof(bool)*n);
    }

    for (int i=0;i<m;i++) {
        for (int k=0;k<n;k++) {
            count=0;
            if (bfs(i,k,m,n,picture,picture[i][k])==true) {
                if (picture[i][k]!=0) {
                    answer[0]++;
                    if (answer[1]<=count) {
                        answer[1]=count;
                    }
                }
                
            }
        }
    }
    
    for (int i=0;i<m;i++) {
        delete [] visited[i];
    }
    delete [] visited;
    
    return answer;
}