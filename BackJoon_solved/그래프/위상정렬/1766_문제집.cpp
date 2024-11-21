#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define f(a,b,c) for(int a = b; a < c; a++)
using namespace std;
const int inf = 1E9;
const int tt = 32001;
int n, m;

int indegree[tt];
vector<int> gh[tt];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<> > q; //
    f(i,0,m) {
        int a, b; cin >> a >> b;
        gh[a].push_back(b);
        indegree[b]++;
    }
    f(i,1,n+1) if (indegree[i] == 0) q.push(i);
    vector<int> ans;

    while(!q.empty()) {
        int loc = q.top(); q.pop(); ans.push_back(loc);
        for (auto e : gh[loc]) {
            indegree[e]--;
            if (indegree[e] == 0) q.push(e);
        }
    }
    for (auto e : ans) cout << e <<' '; return 0;
}