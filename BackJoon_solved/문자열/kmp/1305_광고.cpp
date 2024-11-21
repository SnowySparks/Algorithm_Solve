#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mpi(const string &a) {
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
    int l; cin >> l;
    string a; cin >> a;
    vector<int> result = mpi(a);
    cout << l - result.back();
    return 0;
}