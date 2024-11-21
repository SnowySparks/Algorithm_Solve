#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int inf = 1E6;
const ll dv = 1E9+7;
ll tree[4*inf+10];
ll dt[inf+1];
ll N, M, K;
ll init(int node, int start, int end) {
    if (start == end) return tree[node] = dt[start];
    int mid = (start + end)/2;
    return tree[node] = (init(node*2, start, mid) * init(node*2+1, mid+1, end))%dv;
}

ll change(int node, int start, int end, int idx, ll chv) {
    if (idx < start || idx > end) return tree[node];
    if (start == end) return tree[node] = chv;
    int mid = (start + end)/2;
    return tree[node] = (change(node*2, start, mid, idx, chv) * change(node*2+1, mid+1, end, idx, chv))%dv;
}

ll tmul(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    ll le = tmul(2*node, start, mid, left, right);
    ll ri = tmul(2*node+1, mid+1, end, left, right);
    return (le * ri)%dv;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> dt[i];
    init(1,0,N-1);
    ll a, b, c;
    for (int i = 0; i < M + K ; i++) {
        cin >> a ;
        if (a == 1) {
            cin >> b >> c;
            b--;
            change(1,0,N-1,b,c);
            dt[b] = c;
        }
        else {
            cin >> b >> c;
            b--; c--;
            cout << tmul(1,0,N-1,b,c) << '\n';
        }
    }
    return 0;
}