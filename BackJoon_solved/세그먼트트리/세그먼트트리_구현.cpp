#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
using namespace std;

class segment_tree {
    private:
        ll *tree;
        ll treesize;
        ll init(vector<ll> &a, int node, int start, int end) {
            if (start == end) return tree[node] = a[start];
            int mid = (start + end)/2;
            return tree[node] = init(a, 2*node, start, mid) + init(a, 2*node+1, mid+1, end);
        }
        void upd(int node, int start, int end, int idx, ll val) {
            if(idx < start || idx > end) return;
            tree[node]+= val;
            if (start != end) {
                upd(2*node, start, (start + end)/2, idx, val);
                upd(2*node+1, (start + end)/2+1, end, idx, val);
            }
        }
        ll tadd(int node, int start, int end, int left, int right) {
            if (left > end || right < start) return 0;
            if (left <= start && end <= right) return tree[node];
            ll lsum = tadd(2*node,start,(start+end)/2,left,right);
            ll rsum = tadd(2*node+1,(start+end)/2+1,end,left,right);
            return lsum+rsum;
        }
    public:
        segment_tree(vector<ll> &a) {
            treesize = a.size()*4+4;
            tree = new(nothrow) ll[treesize]; //실패시 nullptr 리턴, 
            if (tree == nullptr ) {cout << "malloc error\n";}
            else {
                init(a, 1, 0, a.size() -1);
            }
        }
        ~segment_tree() {
            delete[] tree;
        }
        void update(int loc, ll change, int len) {
            upd(1,0,len-1,loc,change);
        }
        ll sum(int s, int e, int len) {return tadd(1,0,len-1,s,e);}
};


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    vector<ll> dt(N);
    for (int i = 0 ; i < N ; i++) cin >> dt[i];

    segment_tree *t = new segment_tree(dt);
    ll a, b, c;
    for (int i = 0 ; i < M + K ; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            t->update(b-1,c - dt[b-1],N);
            dt[b-1] = c;
        }
        else {
            cout << t->sum(b-1,c-1,N) << '\n';
        }
    }
    delete t;
    return 0;
}