#include <iostream>
#include <cstring>
using namespace std;
using p = pair<int, int>;
const int inf = 1E5+1;
int dt[inf];
p tree[3*inf];

p init(int node, int s, int e) {
    if (s == e) return tree[node] ={s, s};
    int mid = (s+e)/2;
    p a1 = init(node*2, s, mid);
    p a2 = init(node*2+1, mid+1, e);
    return tree[node] = {min(a1.first, a2.first), max(a1.second, a2.second)};
}

p upd(int node ,int s, int e, int idx, int num) {
    if (idx < s || idx > e) return tree[node];
    if (s == e) return tree[node] = {num, num};
    int mid = (s+e)/2;
    p a1 = upd(node*2, s, mid, idx, num);
    p a2 = upd(node*2+1, mid+1, e, idx, num);
    return tree[node] = {min(a1.first, a2.first), max(a1.second, a2.second)};
}

p q(int node, int s, int e, int l, int r) {
    if (e < l || r < s) return {1e9, -1e9};
    if (l <= s && e <= r) return tree[node];
    int mid = (s+e)/2;
    p a1 = q(2*node,s,mid,l,r);
    p a2 = q(2*node+1, mid+1,e,l,r);
    return {min(a1.first,a2.first),max(a1.second,a2.second)};
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int N, K;
    int a,b,c;
    while(T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) dt[i] = i;
        init(1,0,N-1);
        while(K--) {
            cin >> a >> b >>c;
            if (a == 0) {
                upd(1,0,N-1,dt[b],c);
                upd(1,0,N-1,dt[c],b);
                swap(dt[b], dt[c]);
            }
            else {
                p re = q(1,0,N-1, b, c);
                //cout << re.first << " " << re.second << '\n';
                if (b == re.first && c == re.second) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }

}