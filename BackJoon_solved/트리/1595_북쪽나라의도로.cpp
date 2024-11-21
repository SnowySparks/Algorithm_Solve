#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > gh[10001]; //비용, 도착노드
bool visited[10001];

int maxnode = 0; int maxdist = 0;

void dfs(int root, int dist) {
    if (visited[root]) return;
    visited[root] = true;
    if (maxdist < dist) {
        maxdist = dist;
        maxnode = root;
    }
    for (auto e : gh[root]) {
        if (visited[e.second]) continue;
        dfs(e.second,e.first+dist);
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a,b,c;
    while( cin >> a >> b >> c) {
        gh[a].push_back({c,b});
        gh[b].push_back({c,a});
    }
    dfs(a,0);
    maxdist = 0;
    for (int i = 0 ; i < 10001 ; i++) visited[i] = false;
    dfs(maxnode,0);
    cout << maxdist; return 0;
}