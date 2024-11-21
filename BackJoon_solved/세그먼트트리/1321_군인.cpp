#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int inf = 5e5+1;
int n, q;
int arr[inf]; 
ll tree[inf*3];

ll init(int node, int s, int e) {
    if (s == e) return tree[node] = arr[s];
    int mid = (s+e)/2;
    return tree[node] =init(2*node,s,mid) + init(2*node+1,mid+1,e);
}

ll change(int node, int s, int e, int idx, ll val) {
    if ( idx < s || idx > e) return tree[node];
    if (s == e) return tree[node] = tree[node] + val;
    int mid = (s+e)/2;
    return tree[node] =change(2*node,s,mid,idx,val) + change(2*node+1,mid+1,e,idx,val);
}

int query(int node, int s, int e, ll loc) {
    if (s == e) return s;
    if (loc == tree[node]) return e;
    int mid = (s+e)/2;
    if (loc > tree[node*2]) return query(2*node+1,mid+1,e,loc-tree[node*2]);
    else return query(2*node,s,mid,loc);
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> arr[i];
    init(1,0,n-1);
    cin >> q;
    int qu, i, a;
    while(q--) {
        cin >> qu;
        if (qu == 1) {
            cin >> i >> a; i--;
            change(1,0,n-1,i,a);
        }
        else {
            cin >> a;
            cout << query(1,0,n-1,a)+1 <<'\n';
        }
    }
    return 0;
}