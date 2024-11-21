#include <iostream>
#include <string>
using namespace std;
#define f(a,b,c) for(int a=b; a<c;a++)

int recur = 0;

int recursion(const string &s) {
    int l = 0, r = s.size()-1; recur = 0;
    while (l <= r) {
        recur++;
        if (s[l]!=s[r]) return 0;
        if (l == r) break;
        l++; r--;
    }
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        recur = 0;
        int ans = recursion(s);
        cout << ans <<' ' << recur << '\n';
    }
    return 0;
}