#include <iostream>
typedef long long ll;
using namespace std;
const int Length = 2e5 + 2;
const int MOD = 1e9 + 7;
int maxX = 0;
ll cost_segTree[Length * 4];
int cnt_segTree[Length * 4];
int input[Length];

void costUpdate(int node, int l, int r, int loc) {
    if (loc < l || r < loc) return;
    if (l == r) {
        cost_segTree[node] += loc;
        return;
    }
    int mid = (l + r) >> 1;
    costUpdate(2 * node, l, mid, loc);
    costUpdate(2 * node + 1, mid + 1, r, loc);
    cost_segTree[node] = cost_segTree[2 * node] + cost_segTree[2 * node + 1];
}

void cntUpdate(int node, int l, int r, int loc) {
    if (loc < l || r < loc) return;
    cnt_segTree[node]++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    cntUpdate(2 * node, l, mid, loc);
    cntUpdate(2 * node + 1, mid + 1, r, loc);
}

ll queryCost(int node, int l, int r, int targetL, int targetR) {
    if (r < targetL || targetR < l) return 0L;
    if (targetL <= l && r <= targetR) return cost_segTree[node];
    int mid = (l + r) >> 1;
    return queryCost(2*node, l, mid, targetL, targetR) + queryCost(2*node +1, mid+1, r, targetL, targetR);
}

int queryCnt(int node, int l, int r, int targetL, int targetR) {
    if (r < targetL || targetR < l) return 0;
    if (targetL <= l && r <= targetR) return cnt_segTree[node];
    int mid = (l + r) >> 1;
    return queryCnt(2*node, l, mid, targetL, targetR) + queryCnt(2*node +1, mid+1, r, targetL, targetR);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> input[i];
    for (int i = 0; i < n; ++i) maxX = max(maxX, input[i]);

    ll ans = 1;

    cntUpdate(1, 0, maxX, input[0]);
    costUpdate(1, 0, maxX, input[0]);

    for (int i = 1; i < n; ++i) {
        int loc = input[i];
        ll leftCost = queryCost(1, 0, maxX, 0, loc-1);
        ll rightCost = queryCost(1, 0, maxX, loc+1, maxX);
        int leftCnt = queryCnt(1, 0, maxX, 0, loc - 1);
        int rightCnt = queryCnt(1, 0, maxX, loc + 1, maxX);

        ll calLeft = 1LL * loc * leftCnt - leftCost;
        ll calRight = rightCost - 1LL * loc * rightCnt;

        ans = (ans * ( (calLeft + calRight)%MOD ) ) % MOD;

        cntUpdate(1, 0, maxX, loc);
        costUpdate(1, 0, maxX, loc);
    }
    cout << ans;
    return 0;
}