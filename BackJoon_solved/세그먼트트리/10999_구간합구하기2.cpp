#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int inf = 1e6+1;
int n, m, k;

ll tree[inf];
ll lazy[inf];
ll arr[inf];

ll init(int n, int s, int e) {
    if (s==e) return tree[n] = arr[s];
    int mid = (s+e)/2;
    return tree[n] = init(2*n,s,mid) + init(2*n+1,mid+1,e);
}

void upd(int n, int s, int e) {
    if (lazy[n]) {
        tree[n] += (e - s + 1) * lazy[n];
        if (s!=e) {
            lazy[2*n] += lazy[n];
            lazy[2*n+1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

ll update(int n, int s, int e, int left, int right, ll val) {
    upd(n,s,e);
    if ( right < s || left > e) return tree[n];
    else if (left <= s && e <= right) {
        tree[n] += (e-s+1)*val;
        if (s!=e) {
            lazy[2*n] += val;
            lazy[2*n+1] += val;
        }
        return tree[n];
    }
    int mid = (s+e)/2;
    return tree[n]  = update(2*n, s, mid, left, right, val) + update(2*n+1, mid+1, e, left, right,val);
}

ll query(int n, int s, int e, int l, int r) {
    upd(n,s,e);
    if ( r < s || l > e) return 0;
    else if (l <= s && e <= r) return tree[n];
    int mid = (s+e)/2;
    return query(2*n,s,mid,l,r) + query(2*n+1,mid+1,e,l,r);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M,K; cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    init(1,0,N-1);
    ll a, b, c, d;
    for (int i = 0; i < M+K ; i ++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(1,0,N-1,b-1,c-1,d);
        }
        else {
            cin >> b >> c;
            cout << query(1,0,N-1,b-1,c-1) << '\n';
        }
    }
}