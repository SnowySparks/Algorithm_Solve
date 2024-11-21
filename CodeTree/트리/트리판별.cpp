#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, root;
vector<int> adj[10001];
int indegree[10001];
bool v[10001];
bool isTree = true;

int node_cnt = 0;

void dfs(int node) {
    ++node_cnt;
    v[node] = true;
    for (int nxt : adj[node]) {
        if (v[nxt]) {
            isTree = false;
            return;
        }
        dfs(nxt);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b; // a->b
        adj[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= 10000; ++i) {
        if (!adj[i].empty() && indegree[i] == 0) {
            if (root == 0) {
                root = i;
            }
            else {
                isTree =false;
                break;
            }
        }
    }

    if (!isTree) {
        cout << 0;
        return 0;
    }


    dfs(root);

    if (node_cnt != m+1) {
        cout << 0;
        return 0;
    }

    cout << 1;
    return 0;
}