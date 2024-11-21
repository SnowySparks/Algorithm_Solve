#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector < set <int>> table(1001);
queue <int> loc;

bool visited[1001];
int re[1001];
int cnt=0;

void dfs (int current) {
    if (visited[current]) return;

    visited[current] = true;
    cout << current <<' ';
    re[current] = cnt;
    for (auto &next : table[current]) {
        if (visited[next]) {
            continue;
        }
        dfs(next);
    }
}

void bfs (int current) {
    while (!loc.empty()) {
        if (!visited[loc.front()]) {
            visited[loc.front()] = true;
            cout << loc.front() << ' ';
            for (int e : table[loc.front()]) {
                loc.push(e);
            }
        }
        loc.pop();
    }
}


int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int v,e,r;
    cin >> v >> e >> r;
    int a,b;

    while (e--) {
        cin >> a >> b;
        table[a].insert(b);
        table[b].insert(a);
    }

    dfs(r);
    for (int i=0;i<=v;i++) {
        visited[i]=false;
    }
    cout <<endl;
    loc.push(r);
    bfs(r);
    
    return 0;

}