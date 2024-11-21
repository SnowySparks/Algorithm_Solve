#include <iostream>
#include <vector>
using namespace std;
string s;

int _pi(const string &a) {
    int len = (int) a.size(), j = 0;
    int ans = 0;
    vector<int> p(len,0);
    for (int i = 1 ; i < len; i++) {
        while ( j > 0 && a[i] != a[j]) j = p[j-1];
        if (a[i] == a[j]) p[i] = (++j);
        ans = max(ans, p[i]);
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s; int ans = 0,  l = (int) s.size();
    for (int i = l ; i > 0; i--) {
        ans = max(ans, _pi(s.substr(l-i,i)));
    }
    cout << ans; return 0;
}