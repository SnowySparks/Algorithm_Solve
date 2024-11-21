#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int inf = 1E6;

ll tree[4*inf+10];
ll dt[inf+1];
ll N, M, K;
ll init(int node, int start, int end) {
    if (start == end) return tree[node] = dt[start];
    int mid = (start + end)/2;
    return tree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
}

void change(int node, int start, int end, int idx, ll chv) {
    if (idx < start || idx > end) return;
    tree[node] += chv;
    if (start != end) {
        int mid = (start + end)/2;
        change(2*node, start, mid, idx, chv);
        change(2*node+1, mid+1, end, idx, chv);
    }
}

ll tsum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end)/2;
    ll le = tsum(2*node, start, mid, left, right);
    ll ri = tsum(2*node+1, mid+1, end, left, right);
    return le + ri;
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
            change(1, 0, N-1, b, c - dt[b]);
            dt[b] = c;
        }
        else {
            cin >> b >> c;
            b--; c--;
            cout << tsum(1,0,N-1,b,c) << '\n';
        }
    }
    return 0;
}