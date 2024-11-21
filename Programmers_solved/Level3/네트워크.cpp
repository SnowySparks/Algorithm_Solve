#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool visited[200];
int answer = 0;

void dfs(int start, int N, const vector<vector<int> > & pc) {
    if (visited[start]) return;
    visited[start] = true;
    for (int i = 0 ; i < N ; i++) {
        if ( i!= start&&pc[start][i]==1 && !visited[i] ) dfs(i,N,pc);
    }
}


int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {visited[i] = false;}
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i,n,computers);
            answer++;
        }
    }
    return answer;
}