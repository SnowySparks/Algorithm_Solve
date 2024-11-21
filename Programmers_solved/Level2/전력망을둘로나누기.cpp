#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> gh[101];
bool visited[101];

void cl(int N) {
    for (int i = 1 ; i <= N ; i++) {
        visited[i] = false;
    }
}
vector<int> cutted;
int dfs(int start) {
    int cnt = 1;
    for (auto e : gh[start]) {
        if (visited[e]) continue;
        if (cutted[0] == start && cutted[1] == e) continue;
        if (cutted[1] == start && cutted[0] == e) continue;
        visited[e] = true;
        cnt+=dfs(e);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1<<30;
    for (auto e : wires) {
        gh[ e[0]].push_back(e[1]);
        gh[ e[1]].push_back(e[0]);
    }
    for (auto e : wires) {
        cutted = e;
        visited[ e[0]] = true;
        int re = dfs(e[0]);
        answer = min(answer , abs(re - (n-re)));
        cl(n);
    }
    return answer;
}