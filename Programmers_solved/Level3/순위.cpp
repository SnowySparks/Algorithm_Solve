//https://school.programmers.co.kr/learn/courses/30/lessons/49191
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

        vector<vector<int>> table(n+1);
        for (auto e : results) {
            table[e[0]].push_back(e[1]);
        }
        vector<int> win(n+1);

        for (int i=1;i<n;i++) {
            win[i]=table.
        }
    
    return answer;
}