#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
const int MAXN = 1e5 + 10;

vector<int> tree[MAXN];

// 각 i번 노드의 진입 시작 - 종료 시점
int in[MAXN];
int out[MAXN];
int cntNode = -1; // 오일러 경로
int lazy[4*MAXN];
int segment[4*MAXN];


void lazy_update(int node, int l, int r) {
    if (lazy[node]) {
        segment[node] += (r - l + 1) * lazy[node];
        if (l != r) {
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void Input() {
    cin >> n >> m;
    int temp;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        if (i > 1) {
            tree[temp].push_back(i);
        }
    }
}

void dfs(int node) {
    in[node] = ++cntNode;
    for (int child : tree[node]) {
        dfs(child);
    }
    out[node] = cntNode;
}

int update(int node, int l, int r, int fr, int to, int val) {
    lazy_update(node, l, r);
    if (r < fr || to < l ) return segment[node];
    else if (fr <= l && r <= to) {
        lazy[node] += val;
        lazy_update(node, l, r);
        return segment[node];
    }
    else {
        int mid = (l + r) >> 1;
        return segment[node] = update(2*node,l,mid,fr,to,val) + update(2*node+1,mid+1,r,fr,to,val);
    }
}

int find(int node, int l, int r, int idx) {
    lazy_update(node, l, r);
    if (idx < l || r < idx) return 0;
    else if (l == r) {
        return segment[node];
    }
    else {
        int mid = (l + r) >> 1;
        return find(2*node,l,mid,idx) + find(2*node+1,mid+1,r,idx);
    }
}

void query() {
    int cmd, i, w;
    while (m--)
    {
        cin >> cmd;
        if (cmd == 1) {
            cin >> i >> w;
            update(1, 0, n-1, in[i], out[i], w);
        }
        else {
            cin >> i;
            cout << find(1, 0, n-1, in[i]) << '\n';
        }        
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    Input();
    dfs(1);
    query();
}