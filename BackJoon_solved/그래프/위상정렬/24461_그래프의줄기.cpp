#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e5;
int n, remain;
vector<int> adj[maxn];
int cnt[maxn];
bool removed[maxn];
bool visited[maxn];
int childRemovedCnt[maxn]; //자기 노드가 삭제된 것이 아니면 

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    remain = n;
    int a, b;
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 3개까지는 무조건 일직선 (트리)
    if (n <= 3) {
        for (int i = 0; i < n; ++i) cout << i << ' ';
        return 0;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() == 1) {
            q.push(i);
        }
    }

    while (q.size() > 2)
    {
        int cnt = q.size();
        for (int i = 0; i < cnt; ++i) {
            int loc = q.front(); q.pop(); visited[loc]=true;
            for (int j : adj[loc]) {
                childRemovedCnt[j]++;
                if (adj[j].size() - childRemovedCnt[j] == 1) {
                    q.push(j);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) cout << i << ' ';
    }

    return 0;
}