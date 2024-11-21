#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
int n, m, st, en;
const int inf = 1e5+1;
vector<pii> gh[inf];
int max_weight[inf];
bool v[inf];

int bfs(int st, int ed, int st_w) {
    memset(v,false,sizeof(v));
    v[st] = true;
    queue<int> q; q.push(st);
    while(!q.empty()) {
        int loc = q.front(); q.pop();
        if (loc == ed) return st_w;
        for (pii e : gh[loc]) {
            if (!v[e.first] && e.second >= st_w) {
                v[e.first]=true;
                q.push(e.first);
            }
        }
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int r = -1, l = 1;
    while(m--) {
        int a,b,c; cin >> a >> b >> c;
        gh[a].push_back({b,c});
        gh[b].push_back({a,c});
        r= max(r,c);
    }
    cin >> st >> en;
    int ans = 0;
    while (l <= r) {
        int mid = (l+r)/2;
        int res = bfs(st,en,mid);
        if (res == -1) r = mid -1;
        else {
            ans = max(ans,mid);
            l = mid +1;
        }
    }
    cout << ans;
    return 0;
    
}