#include <iostream>
#include <vector>
#include <cstring>
#define f(a, b, c) for(int a= b;a<c;++a)
using namespace std;
const int MAX_C = 65535;
int n, k;
int arr[MAX_C+2];
int tree[3*(MAX_C+2)];

void update(int node, int l, int r, int val) {
    if (l == r) {
        if (val > 0) tree[node]++;
        else tree[node]--;
        return;
    }
    if (val < l || val > r) return;

    int mid = (l + r) >> 1;
    update(2*node, l, mid, val);
    update(2*node+1, mid+1, r, val );

    tree[node] = tree[2*node] + tree[2*node + 1];
}

int query(int node, int l, int r, int cnt) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (tree[node] <= cnt ) {
        return query(node * 2, l , mid, cnt);
    }
    else {
        return query(2 * node + 1, mid + 1, r, cnt - tree[node]);
    }
}



int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    f(i, 0, n) cin >> arr[i];
    long long ans = 0;
    f(i, 0, n) {
        update(1, 0, MAX_C, arr[i]);
        if (i >= k) {
            int cal = query(1, 0, MAX_C, (i+1)/2 + ((i+1)%2));
            ans += 1LL * cal;
            cout << cal << '\n';
        }
    }
    cout << ans;

    return 0;
}