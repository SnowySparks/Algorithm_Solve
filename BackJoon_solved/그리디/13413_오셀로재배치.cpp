#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;
#define f(a,b,c) for(int a=b; a<c;a++)

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string a1 ,a2; cin >> a1 >> a2;
        int b1 = 0, b2 = 0, diff = 0;

        f(i,0,n) {
            if (a1[i] == 'B') b1++;
            if (a2[i] == 'B') b2++;
            if (a1[i] != a2[i]) diff++;
        }
        int ans = 0;
        ans += abs(b1 - b2);
        diff -= ans;
        ans += diff/2;
        cout << ans <<'\n';
    }
}