#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define f(a,b,c) for (int a=b;a<c;a++)
using namespace std;
int n, m;
vector<int> gh[501];
bool v[501];
bool yestree = true;
int node, edge;
bool istree(int root) {
    v[root] =true;
    node = 1; edge = 0;
    queue<int> q; q.push(root);
    while (!q.empty()) {
        int loc = q.front(); q.pop();
        edge += (int)gh[loc].size();
        for (int e : gh[loc]) {
            if (!v[e]) {
                node++;
                v[e] = true;
                q.push(e);
            }
        }
    }
    return (edge/2)+1 == node ? true:false;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    for(int t = 1; ; t++) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        f(i,0,n+1) gh[i].clear();
        memset(v,false,sizeof(v));
        while(m--) {
            int a,b; cin >> a>>b;
            gh[a].push_back(b);
            gh[b].push_back(a);
        }
        int cnt = 0;
        for (int i = 1 ; i <= n ; i++) {
            if (!v[i]) {
                bool res = istree(i);
                if (res) cnt++;
                
            }
        }
        if (cnt == 0) cout << "Case " << t <<": No trees.\n";
        if (cnt == 1) cout << "Case " << t <<": There is one tree.\n";
        if (cnt > 1) cout << "Case " << t <<": A forest of "<<cnt<< " trees.\n";
    }
    return 0;
}