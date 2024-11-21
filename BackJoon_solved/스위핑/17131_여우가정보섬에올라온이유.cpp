#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define f(a, b, c) for(int a=b;a<c;++a)
const int max_n = 2e5+1;
const ll mod = 1e9+7;
unordered_map<int, int> grid;
int n, grid_cnt = 0;
pii pts[max_n];
ll tree[max_n*3];
ll cnt[max_n];

void init(int node, int l, int r) {
    if (l == r) {
        tree[node] = cnt[l];
        return;
    }
    int mid = (l + r) >> 1;
    init(2*node, l, mid);
    init(2*node+1, mid+1, r);
    tree[node] = tree[2*node] + tree[2*node+1];
    return;
}

void update(int node, int l, int r, int idx) {
    if ( idx < l || idx > r) return;
    tree[node]--;
    if (l == r) return;
    int mid = (l + r) >> 1;
    update(2*node, l, mid, idx);
    update(2*node+1, mid+1, r, idx);
}

ll query(int node, int l, int r, int fr, int to) {
    if (to < l || r < fr) return 0;
    else if (fr <= l && r <= to) return tree[node];
    int mid = (l + r) >> 1;
    return query(2*node,l,mid,fr,to) + query(2*node+1,mid+1,r,fr,to);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    f(i,0,n) cin >> pts[i].first >> pts[i].second;
    sort(pts, pts+n);
    f(i,0,n) {
        if (grid.find(pts[i].first) == grid.end()) grid[pts[i].first] = grid.size();
        cnt[grid[pts[i].first]]++;
    }
    grid_cnt = grid.size();
    init(1,0,grid_cnt-1);

    // y오름차순, 그리고 x오름차순
    sort(pts, pts+n, [](const pii &a, const pii &b) {
        return (a.second == b.second) ? a.first < b.first : a.second < b.second;
    });

    int fr = -1, to = -1; //같은 y축 범위에 대한 것
    ll ans = 0;
    while (true)
    {
        fr = to + 1;
        to++;
        if (fr == n) break;
        while (to + 1 < n && pts[to+1].second == pts[fr].second) ++to;
        // cout << fr << ' ' << to << " : range\n";
        f(i, fr, to+1) update(1, 0, grid_cnt-1, grid[pts[i].first]);

        f(i, fr, to+1) {
            if (grid[pts[i].first] == 0 || grid[pts[i].first] == grid_cnt-1) continue; 
            ll left = query(1, 0, grid_cnt-1, 0, grid[pts[i].first]-1);
            ll right = query(1, 0, grid_cnt-1, grid[pts[i].first]+1, grid_cnt-1);
            // cout << left <<' ' << right << '\n';
            ans+= left*right;
            ans %= mod;
        }
    }
    
    cout << ans%mod;
    return 0;
}