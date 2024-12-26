#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ADD 0
#define MUL 1
#define SET 2
using ll = long long;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
int n, m;
int x, y, q;
ll v;
ll arr[MAXN];
ll tree[4*MAXN];
ll lazy[4*MAXN][2];

void init(int node, int l , int r) {
    lazy[node][MUL] = 1;
    if (l == r) {
        tree[node] = arr[r];
        return;
    }
    int mid = (l + r) >> 1;
    init(2*node,l, mid);
    init(2*node+1, mid+1,r);
    tree[node] = (tree[2*node] + tree[2*node+1])%MOD;
}

void lazy_update(int node, int l, int r) {
    if (lazy[node][MUL] != 1) {
        tree[node] *= lazy[node][MUL];
        tree[node] %= MOD;
        if (l != r) {
            // 곱하기는 lazy의 ADD 와관련된 것도 영향을 줌
            lazy[2*node][MUL] *= lazy[node][MUL];
            lazy[2*node][MUL] %= MOD;
            lazy[2*node+1][MUL] *= lazy[node][MUL];
            lazy[2*node+1][MUL] %= MOD;
            lazy[2*node][ADD] *= lazy[node][MUL];
            lazy[2*node][ADD] %= MOD;
            lazy[2*node+1][ADD] *= lazy[node][MUL];
            lazy[2*node+1][ADD] %= MOD;
        }
        lazy[node][MUL] = 1;
    }
    if (lazy[node][ADD]) {
        tree[node] += ((r - l + 1) * lazy[node][ADD])%MOD;
        tree[node] %= MOD;
        if (l != r) {
            lazy[2*node][ADD] += lazy[node][ADD];
            lazy[2*node][ADD] %= MOD;
            lazy[2*node+1][ADD] += lazy[node][ADD];
            lazy[2*node+1][ADD] %= MOD;
        }
        lazy[node][ADD] = 0;
    }
    return;
}

// node, array탐색(l - r), 업데이트 구간 (fr - to), val : v, state : ADD or MUL
ll update(int node, int l, int r, int fr, int to, ll val, int state) {
    lazy_update(node,l,r);
    if (r < fr || to < l) return tree[node];
    else if (fr <= l && r <= to) {
        if (state == SET) {
         // SET 명령어
        // 먼저 곱하기 0을 하고 난뒤, 다시 ADD를 하는 방식 
            lazy[node][MUL] = 0;
            lazy[node][ADD] = val;
        }
        else {
            lazy[node][state] = val;
        }
        lazy_update(node, l, r);
        return tree[node];
    }
    else {
        int mid = (l + r) >> 1;
        return tree[node] = (update(2*node, l, mid, fr, to, val, state) + update(2*node+1, mid+1, r, fr, to, val, state))%MOD;
    }
}
ll query(int node, int l, int r, int fr, int to) {
    lazy_update(node,l,r);
    if (r < fr || to < l) return 0;
    else if (fr <= l && r <= to) return tree[node];
    else {
        int mid = (l + r) >> 1;
        return (query(2*node, l, mid, fr, to) + query(2*node + 1,mid +1, r, fr, to))%MOD;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >>arr[i];
    init(1, 0, n-1);
    cin >> m;
    for (int i = 1; i <= m; ++i) {
                /* code */
        cin >> q;
        switch (q)
        {
        case 1: // ADD 
        case 2: // MUL
        case 3: // SET
            cin >> x >> y >> v;
            update(1, 0, n-1, x-1, y-1, v, q-1);
            break;
        case 4:
            cin >> x >> y;
            cout << query(1, 0, n-1, x-1, y-1) << '\n';
            break;
        default:
            break;
        }
    }
    
    return 0;
}