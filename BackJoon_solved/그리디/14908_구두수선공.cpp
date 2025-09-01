#include <iostream>
#include <algorithm>
using namespace std;
struct info {
    int t, s, idx;
};
info arr[1000]; // {t_i, s_i}
int n;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i].t >> arr[i].s;
        arr[i].idx = i + 1;
    }
    sort(arr, arr + n, [](const info &a, const info &b) {
        if (a.s * b.t == b.s * a.t) return a.idx < b.idx;
        return a.s * b.t > b.s * a.t;
    });
    for (int i = 0; i < n; ++i) {
        cout << arr[i].idx << ' ';
    }


    return 0;
}