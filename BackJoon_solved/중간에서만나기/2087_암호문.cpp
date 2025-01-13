#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
int a[40], n, k;
int totalA = 0;
int l, r;
unordered_map<int, int> leftInfo;

string binary(int n, int len) {
    string str = "";
    while (n)
    {
       str.push_back((n&1 ? '1' : '0'));
       n >>= 1;
    }
    
    while (str.size() < len)
    {
        str.push_back('0');
    }
    return str;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        totalA += a[i];
    }
    cin >> k;
    l = n/2;
    r = n - l;

    // left
    for (int i = 0 ; i < (1 << l) ; ++i) {
        int cal = 0;
        string bin = binary(i, l);
        for (int p = 0; p < l; ++p) {
            if (i & (1 << p)) cal += a[p];
        }
        leftInfo[cal] = i;
    }
    string ans = "";
    // right
    for (int i = 0; i < (1 << r); ++i) {
        int cal = 0;
        for (int p = 0; p < r; ++p) {
            if (i & (1 << p)) cal += a[l + p];
        }

        if (leftInfo.find(k - cal) != leftInfo.end()) {
            ans = binary(leftInfo[k-cal], l) + binary(i, r);
            break;
        }
    }
    cout << ans;
    return 0;
}