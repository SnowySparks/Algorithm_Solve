#include <iostream>
#include <vector>
using namespace std;
const int inf = 1E5+1;
const int tmax = 2E9, tmin = -2E9;

int dt[inf+1];
int tree[4*inf][2]; //최소값, 최대값

int pd(int a, int b, int c) {
    if (c == 0) return min(a,b);
    return max(a,b);
}
int init(int node, int start, int end, int md) {
    if (start == end) return tree[node][md] = dt[start];
    int mid = (start + end)/2;
    return tree[node][md] = pd(init(node*2, start, mid, md), init(node*2 +1,mid+1,end,md),md);
}


int chs(int node, int start, int end, int left, int right,int md) {
    if (end < left || start > right) return (md == 0) ? tmax : tmin;
    if (left <= start && end <= right) return tree[node][md];
    int mid = (start + end)/2;
    int l = chs(2*node, start, mid, left, right, md);
    int r = chs(2*node + 1, mid+1, end, left, right, md);
    return pd(l, r,md);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

}