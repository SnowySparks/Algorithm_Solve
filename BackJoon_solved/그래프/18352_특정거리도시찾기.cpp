#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> gh[300001];
int visited[300001];

void bfs(int start) {
    visited[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int loc = q.front(); q.pop();
        for (auto e : gh[loc]) {
            if (visited[e] == -1) {
                q.push(e);
                visited[e] = visited[loc]+1;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K, X; cin >> N >> M >> K >> X; //도시개수, 도로개수, 찾을거리, 시작지점
    int a,b;
    while(M--) {
        cin >>a >> b;
        gh[a].push_back(b);
    }
    for (int i =1  ; i <= N ; i++) {
        visited[i] = -1;
    }
    bfs(X);
    vector<int> lst;
    for (int i =1 ; i <= N ; i++) {
        if (visited[i] == K) lst.push_back(i);
    }
    if (lst.empty()) cout << -1;
    else {
        for (auto e : lst) cout << e <<'\n';
    }
    return 0;

}