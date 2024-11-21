#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> gh[51];

int dfs(int root) {
    if (gh[root].size() == 0) return 0; //리프노드
    vector<int> weight;//아니면 전부 일단 결과값 모으기
    for (auto e : gh[root]) {
        weight.push_back(dfs(e));
    }
    int cnt = 0;
    sort(weight.begin(), weight.end(),greater<int>());
    for (int i = 0 ; i < weight.size() ; ++i) {
        cnt = max(cnt, weight[i]+i);
    }
    return cnt+1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N; int inp;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        if (inp == -1) continue;
        gh[inp].push_back(i);
    }
    cout << dfs(0); return 0;
}
