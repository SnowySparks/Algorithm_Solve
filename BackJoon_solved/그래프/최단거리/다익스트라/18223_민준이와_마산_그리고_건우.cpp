#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)
int v,e,p;
using pii = pair<int,int>;
vector<pii > gh[5001];
const int inf = 1e9+1;

int dist[5001];

int direkstra(int st, int end) {
    fill(dist,dist+v+1,inf);
    dist[st] = 0;
    priority_queue<pii> pq;
    pq.push({0,st});

    while(!pq.empty()) {
        int d = - pq.top().first, loc = pq.top().second; pq.pop();
        if (dist[loc] < d ) continue;
        for (auto e : gh[loc]) {
            int rd = d + e.first, nxt = e.second;
            if (dist[nxt] > rd) {
                dist[nxt] = rd;
                pq.push({-rd,nxt});
            }
        }
    }
    return dist[end];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> v >> e  >> p;
    int a, b, c;
    f(i,0,e) {
        cin >> a >> b >> c;
        gh[a].push_back({c,b});
        gh[b].push_back({c,a});
    }

    direkstra(1,p);

    int vsort = dist[v];
    int top = dist[p];
    int p_to_v = direkstra(p,v);

    if (vsort == top + p_to_v) cout << "SAVE HIM";
    else cout <<"GOOD BYE";
}