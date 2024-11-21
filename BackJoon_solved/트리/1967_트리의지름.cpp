#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int maxDist=0, maxNode = 0;

bool visited[10001];

vector< pair <int, int>> dt[10001]; //거리, 노드위치

void dfs(int node, int dist) {
    if (visited[node]) return ;
    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }
    visited[node] = true;

    for (int i = 0 ; i < dt[node].size() ; i++) {
        dfs(dt[node][i].first, dt[node][i].second + dist); //연결된 곳들 전부 조치
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n ; cin >> n;
    int a,b,c;
    for (int i = 0 ; i < n-1 ; i++) {
        cin >> a >> b >> c;
        dt[a].push_back({b,c});
        dt[b].push_back({a,c});
    }
    dfs(1,0);
    memset(visited, 0, sizeof(visited));
    maxDist =0;
    dfs(maxNode,0);

    cout << maxDist <<'\n';


    return 0;
}