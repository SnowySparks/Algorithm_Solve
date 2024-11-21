#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mpi(const vector<int> &a) {
    int ln = (int) a.size(), j = 0;
    vector<int> res(ln,0);
    for (int i = 1 ; i < ln ; i++) {
        while (j > 0 && a[i]!=a[j]) j = res[j-1];
        if (a[i]==a[j]) res[i] = ++j;
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> res(n,0);
    for (int i = n-1; i >= 0 ; i--) cin >> res[i];
    vector<int> p = mpi(res);

    int max_k = -1, cnt = 0;
    for (int i = 1 ; i < n ; i++) {
        if (p[i] != 0) {
            if (max_k < p[i]) {
                max_k = p[i];
                cnt = 1;
            }
            else if (max_k == p[i]) cnt++;
        }
    }
    if (max_k == -1) cout << max_k;
    else cout << max_k << ' ' << cnt;
    return 0;
}