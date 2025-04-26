#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define f(a, b, c) for(int a=b; a<c; ++a)
#define FRIEND 'F'
#define ENEMY 'E'
int n, m;

int parent[1001];
bool isCounted[1001];
vector<int> adj[1001];

int findp(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findp(parent[x]);
}

bool unite(int a, int b) {
    a = findp(a);
    b = findp(b);
    if (a == b) return false;
    parent[max(a, b)] = min(a, b);
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    f(i, 1, n+1) parent[i] = i;
    char ch; int p, q;
    f(i, 0, m) {
        // 친구면 그룹핑
        cin >> ch >> p >> q;
        if (ch == FRIEND) {
            unite(p, q);
        }
        // 아니면 일단 그래프로 연결
        else {
            adj[p].push_back(q);
            adj[q].push_back(p);
        }
    }

    // 원수의 원수는 친구 -> 한 노드 기준으로 연결된 다른 모든 노드들끼리는 친구
    f(i, 1, n+1) {
        if (adj[i].size() > 1) {
            f(j, 0, adj[i].size()-1) {
                unite(adj[i][j], adj[i][j+1]);
            }
        }
    }
    int ans = 0;
    f(i, 1, n+1) {
        int p = findp(i);
        if (!isCounted[p]) {
            ++ans;
            isCounted[p] = true;
        }
    }
    cout << ans;
    return 0;
}