#include <cstdio>
#include <queue>
using namespace std;
#define K 2500
#define MAX_DEGREE 65536
#define N 250000
typedef long long ll;

int n, k;
int tree[MAX_DEGREE * 4];

void plusUpdate(int node, int l, int r, int degree) {
    if (degree < l || r < degree) return;
    tree[node]++;
    if (l == r) return;

    int mid = (l + r) >> 1;
    plusUpdate(2 * node, l, mid, degree);
    plusUpdate(2 * node + 1, mid + 1, r, degree);
}

void minusUpdate(int node, int l, int r, int degree) {
    if (degree < l || r < degree) return;
    tree[node]--;
    if (l == r) return;

    int mid = (l + r) >> 1;
    minusUpdate(2 * node, l, mid, degree);
    minusUpdate(2 * node + 1, mid + 1, r, degree);
}

int query(int node, int l, int r, int loc) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (tree[2 * node] >= loc) {
        return query(2 * node, l, mid, loc);
    }
    else {
        return query(2 * node + 1, mid + 1, r, loc - tree [2 * node]);
    }
}

int main(void) {
    // freopen("input.txt","r",stdin);
    scanf("%d %d", &n, &k);

    queue<int> q;
    int inputDegree = 0;
    ll answer = 0LL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &inputDegree);

        q.push(inputDegree);
        plusUpdate(1, 0, MAX_DEGREE, inputDegree);
        
        if (i < k - 1) continue;

        if (q.size() > k) {
            minusUpdate(1, 0, MAX_DEGREE, q.front());
            q.pop();
        }

        int res = query(1, 0 , MAX_DEGREE, (k + 1) >> 1 );

        answer += res;
        
    }
    printf("%lld", answer);
    return 0;
}