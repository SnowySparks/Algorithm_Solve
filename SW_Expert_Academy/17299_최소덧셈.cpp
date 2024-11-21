#include <iostream>
#include <algorithm>
using namespace std;
#define f(a,b,c) for (int a=b;a<c;a++)
 
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    f(i,1,t+1) {
        string s; cin >> s;
        int ans = 1e9;
        f(d,1,s.size()) {
            ans = min(ans, stoi(s.substr(0,d)) + stoi(s.substr(d,s.size()-d)));
        }
        cout << '#' << i << ' ' << ans << '\n';
    }
 
    return 0;
 
}