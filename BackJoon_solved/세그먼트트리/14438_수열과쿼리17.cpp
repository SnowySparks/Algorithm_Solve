#include <iostream>
using namespace std;
#define f(a,b,c) for(int a=b; a<c; a++)
const int t = 1e5+1;
const int inf = 1e9+1;
int arr[t];
int tree[t*4];

int init(int n, int s, int e) {
    if (s==e) return tree[n] = arr[s];
    int mid = (s+e)/2;
    return tree[n] = min(init(2*n,s,mid),init(2*n+1,mid+1,e));
}

int update(int n ,int s, int e, int loc, int val) {
    if ( loc < s || loc > e ) return tree[n];
    if (s==e) return tree[n] = val;
    int mid = (s+e)/2;
    return tree[n]  = min( update(2*n, s, mid, loc, val) , update(2*n+1, mid+1, e, loc,val) );
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l) return inf;
    if (l <= s && e <= r) return tree[n];
    int mid = (s+e)/2;
    return min( query(2*n,s,mid,l,r) , query(2*n+1,mid+1,e,l,r) );
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n ; cin >> n;
    f(i,0,n) cin >> arr[i];
    init(1,0,n-1);
    int m; cin >> m;
    while (m--) {
        int q, a, b; cin >> q >> a >> b;
        if (q==1) update(1,0,n-1,a-1,b);
        else cout << query(1,0,n-1,a-1,b-1) << '\n';
    }
    return 0;
}