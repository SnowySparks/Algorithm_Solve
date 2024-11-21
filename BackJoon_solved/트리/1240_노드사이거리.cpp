#include <iostream>
#include <vector>
#include <algorithm>
#define inf 987654321
using namespace std;

vector<pair<int,int> > gh[1001];
int visited[1001];

void dfs(int start) {
    for (auto e : gh[start]) {
        if (visited[e.first] != inf) continue;
        visited[e.first] = min(visited[e.first], visited[start] + e.second);
        dfs(e.first);
    }
}

void re(int N) {
    for (int i = 1 ; i <= N ; i++) visited[i] = inf;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b >> c;
        gh[a].push_back({b,c});
        gh[b].push_back({a,c});
    }
    re(N);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        visited[a] = 0;
        dfs(a);
        cout << visited[b] << '\n';
        re(N);
    } return 0;
}