#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define f(a, b, c) for()
using namespace std;
int n;
vector<int> adj[100001];
int visiteOrder[100001];
bool v[100001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        int tmp; cin >> tmp;
        visiteOrder[tmp] = i;
    }

    if (visiteOrder[1] != 1) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end(),[](int a,int b) {
                return visiteOrder[a] < visiteOrder[b];
        });
    }
    queue<int> q; q.push(1); v[1] = true;
    bool isBFS = (visiteOrder[1] == 1);
    int cnt = 2;
    while (!q.empty() && isBFS)
    {
        int node = q.front(); q.pop();
        for (int child : adj[node]) {
            if (v[child]) continue;

            if (!v[child] && visiteOrder[child] == cnt ) {
                v[child] = true;
                ++cnt;
                q.push(child);
            }
            else if (visiteOrder[child] != cnt) {
                isBFS = false;
                break;
            }
        }
    }
    cout << (isBFS ? 1 : 0);
    return 0;
}