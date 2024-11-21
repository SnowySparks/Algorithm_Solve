#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n,q;
const int v = 1e5+1;
const int inf = 1e9+10;
int arr[v];
int tree[3*v];

int minidx(int x, int y) {
    if (x == -1) return y;
    if (y == -1) return x;
    if (arr[x] == arr[y]) return min(x,y);
    return arr[x] <= arr[y] ? x : y;
}

int init(int node, int s, int e) {
    if (s == e) return tree[node] = s;
    int m = (s+e)/2;
    return tree[node] = minidx(init(2*node,s,m), init(2*node+1,m+1,e));
}

int upd(int node, int s, int e, int idx) {
    if (s > idx || e < idx) return tree[node];
    if (s == e) return tree[node];
    int m = (s+e)/2;
    return tree[node] = minidx(upd(2*node,s,m,idx), upd(2*node+1,m+1,e,idx));
}

int query(int node, int s, int e, int l, int r) {
    if (s > r || e < l) return -1;
    if (l <= s && e <= r) return tree[node];
    int m = (s+e)/2;
    return minidx(query(2*node,s,m,l,r),query(2*node+1,m+1,e,l,r));
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    init(1,0,n-1);
    cin >> q;
    int quest, i, v;
    while (q--) {
        cin >> quest >> i >> v;
        if (quest == 1) {
            arr[i-1] =v;
            upd(1,0,n-1,i-1);
        }
        else cout << 1 + query(1,0,n-1,i-1,v-1) << '\n';
    }
    return 0;
}