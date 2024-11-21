#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> gh[10001];
bool visited[10001];
int tt[10001];

int cnt = 0;
void dfs(int start) {
    cnt++;
    visited[start] = true;
    for (auto e : gh[start]) {
        if (!visited[e]) dfs(e);
    }
}

void clean(int N) {
    for (int i = 1 ; i <= N ; i++) visited[i] = false;
}
int main(void) {
    int N, M; cin >> N; cin >> M;
    int a,b;
    cnt = 0;
    while(M--) {
        cin >> a >> b;
        gh[b].push_back(a);
    }
    int max_value = -1;
    for (int i =1 ; i <= N ; i++) {
        dfs(i);
        max_value = max(max_value,cnt); clean(N);
        tt[i] = cnt;
        cnt = 0;
    }
    vector<int> lst;
    for (int i = 1 ; i <= N ; i++) {
        if (tt[i] == max_value) lst.push_back(i);
    }

    for (auto e : lst) cout << e << ' '; 
    return 0;

}