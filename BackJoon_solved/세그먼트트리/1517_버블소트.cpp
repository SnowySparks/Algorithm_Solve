#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;
const int inf = 5e5+10;
#define f(a, b, c) for (int a = b; a < c; ++a)
unordered_map<int, int> compr_num; //수 압축
int n;
int arr[inf];
int sort_arr[inf];
long long tree[3*inf];

long long update(int node, int l, int r, int idx) {
    if (idx < l ||  r < idx) return tree[node];
    if (l == r) return tree[node] = tree[node]+1;
    int mid = (l + r) >> 1;
    return tree[node] = update(2*node, l, mid, idx) + update(2*node + 1, mid+1, r, idx);
}

long long q(int node, int l, int r, int s, int e = n) {
    if (e < l || r < s) return 0;
    else if (s <= l && r <= e) return tree[node];
    int mid = (l + r) >> 1;
    return q(2*node, l, mid, s, e) + q(2*node + 1, mid+1, r, s, e);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 0, n) {
        cin >> arr[i];
        sort_arr[i] = arr[i];
    }
    sort(sort_arr, sort_arr+n);
    f(i, 0, n) compr_num[sort_arr[i]] = i;

    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        int num = arr[i];
        int loc = compr_num[num];
        update(1, 0, n, loc);
        ans += q(1, 0, n, loc+1);

    }
    cout << ans;
    return 0;
}

// 원리
// 먼저 update는 입력 순으로 함
// 현재 x 라는 수가 있으면 x는 오름차순으로 idx 번째에 있으니 해당 idx위치에 +1하는걸 함
// 그리고 idx + 1 부터 저 오른쪽 끝까지의 수의 합들을 ans에 갱신