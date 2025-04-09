#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+1;
int tree[MAXN*4], n;
int ans[MAXN];
int num = 1;

void update(int idx, int l, int r, int cnt) {
    tree[idx]++;
    if (l == r) {
        ans[l] = num++;
        return;
    }
    int mid = (l + r) >> 1;
    int left = mid - l + 1;
    if (left-tree[2*idx] > cnt) update(2*idx,l,mid,cnt);
    else update(2*idx + 1, mid+1,r, cnt - (left-tree[2*idx]));
    return;
}   

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        update(1,0,n-1,tmp);
    }

    for (int i = 0; i < n; ++i) cout << ans[i] <<'\n';
    return 0;
}
