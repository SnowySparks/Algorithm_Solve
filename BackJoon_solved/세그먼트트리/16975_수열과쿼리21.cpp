#include <iostream>
using namespace std;
using ll = long long;
const int mt = 1E6+1;
ll dt[mt];
ll tree[3*mt];
ll lazy[3*mt];

ll init(int n, int s, int e) {
    if (s == e) return tree[n] = dt[s];
    int mid = (s+e)/2;
    return tree[n] = init(2*n ,s, mid) + init(2*n+1,mid+1,e);
}

void lazy_update(int n, int s, int e) {
    if (lazy[n]!=0) {
        tree[n]+= (e-s+1)*lazy[n];
        if (s!=e) {
            lazy[2*n] += lazy[n];
            lazy[2*n+1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

ll update(int n, int s, int e ,int l, int r, ll val) {
    lazy_update(n,s,e);
    if ( r < s || l > e) return tree[n];
    if (l <= s && e <= r) {
        tree[n] += (e-s+1)*val;
        if (s != e) {
            lazy[2*n] += val;
            lazy[2*n+1] += val;
        }
        return tree[n];
    }
    int mid=(s+e)/2;
    return tree[n] = update(2*n,s,mid,l,r,val) + update(2*n+1,mid+1,e,l,r,val);
}

ll q(int n, int s, int e, int l, int r) {
    lazy_update(n,s,e);
    if ( r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[n];
    int mid = (s+e)/2;
    return q(2*n,s,mid,l,r) + q(2*n+1,mid+1,e,l,r);
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
            update(1,0,N-1,b-1,c-1,d);
        }
        else {
            cin >> b;
            cout << q(1,0,N-1,b-1,b-1) << '\n';
        }
    }
}
