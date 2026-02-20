#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define RED 1
#define BLUE -1
#define EMPTY 0
const int N = 2'001;
int v[N];

int n, m;
vector<int> adj[N];

void init() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void bigraph(int start_node) {
    queue<int> q;
    q.push(start_node);
    v[start_node] = RED;
    while (!q.empty())
    {
        int node = q.front(); q.pop();
        for (int nxt : adj[node]) {
            if (v[nxt] != EMPTY) continue;
            v[nxt] = -v[node];
            q.push(nxt);
        }
    }
}

bool is_bigraph(int node) {
    for (int nxt : adj[node]) {
        if (v[nxt] == v[node]) {
            return false;
        }
    }
    return true;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    init();
    for (int i = 1; i <= n; ++i) {
        if (v[i] == EMPTY) {
            bigraph(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!is_bigraph(i)) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}