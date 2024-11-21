#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define f(a,b,c) for(int a = b; a < c; a++)
const int mt = 1E5+1;
int dt[mt];
ll tree[3*mt];

ll init(int n, int s, int e) {
    if (s == e) return tree[n] = dt[s];
    int mid = (s+e)/2;
    return tree[n] = init(2*n,s,mid) + init(2*n+1,mid+1,e);
}

ll change(int n, int s, int e, int idx, int val) {
    if ( idx < s || idx > e) return tree[n];
    if ( s==e) return tree[n] = val;
    int mid = (s+e)/2;
    return tree[n] = change(2*n, s, mid, idx, val) + change(2*n+1, mid+1, e, idx, val);
}

ll q(int n, int s, int e, int l, int r) {
    if (e < l || s > r) return 0;
    if (l <= s && e <= r) return tree[n];
    int mid = (s+e)/2;
    return q(2*n,s,mid,l,r) + q(2*n+1,mid+1,e,l,r);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, Q; cin >> N >> Q;
    f(i,0,N) cin >> dt[i];
    init(1,0,N-1);
    int a, b, c, d;
    f(i,0,Q) {
        cin >> a >> b >> c >> d;
        if(a>b) swap(a,b);
        cout << q(1,0,N-1,a-1,b-1) <<'\n';
        change(1,0,N-1,c-1,d);
    }
    return 0;
}