#include <iostream>
using namespace std;
using ll = long long;
const int mt = 5E5+1;
int dt[mt];
int tree[4*mt];
int lazy[4*mt];

int init(int n, int s, int e) {
    if (s == e) return tree[n] = dt[s];
    int mid = (s+e)/2;
    return tree[n] = init(2*n ,s, mid) ^ init(2*n+1,mid+1,e);
}

void lazy_update(int n, int s, int e) {
    if (lazy[n]!=0) {
        if ((s-e+1)%2) tree[n] ^=lazy[n];
        if (s!=e) {
            lazy[2*n] ^= lazy[n];
            lazy[2*n+1] ^= lazy[n];
        }
        lazy[n] = 0;
    }
}

int update(int n, int s, int e ,int l, int r, int val) {
    lazy_update(n,s,e);
    if ( r < s || l > e) return tree[n];
    if (l <= s && e <= r) {
        if ((e-s+1)%2) tree[n] ^=val;
        if (s != e) {
            lazy[2*n] ^= val;
            lazy[2*n+1] ^= val;
        }
        return tree[n];
    }
    int mid=(s+e)/2;
    return tree[n] = update(2*n,s,mid,l,r,val) ^ update(2*n+1,mid+1,e,l,r,val);
}

ll q(int n, int s, int e, int l, int r) {
    lazy_update(n,s,e);
    if ( r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[n];
    int mid = (s+e)/2;
    return q(2*n,s,mid,l,r) ^ q(2*n+1,mid+1,e,l,r);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> dt[i];
    init(1,0,N-1);
    int M; cin >> M;
    ll a, b, c, d;
    for (int i = 0; i < M ; i ++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(1,0,N-1,b,c,d);
        }
        else {
            cin >> b >> c;
            cout << q(1,0,N-1,b,c) << '\n';
        }
    }
}
