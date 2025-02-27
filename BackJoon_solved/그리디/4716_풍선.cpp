#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, b;
struct team{
    int k, da, db;
};
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    while(true) {
        cin >> n >> a >> b;
        if (n == 0 && a == 0 && b == 0) break;
        vector<team> teams(n);
        for (team &t : teams) {
            cin >> t.k >> t.da >> t.db;
        }
        long long ans = 0;
        sort(teams.begin(), teams.end(), [](const team &i, const team &j){
            int gapA = abs(i.da - i.db);
            int gapB = abs(j.da - j.db);
            return gapA > gapB;
        });
    
        for (auto &[k, da, db] : teams) {
            int getA = 0, getB = 0;
            if (da < db) {
                getA = min(a, k);
                getB = k-getA;
            }
            else {
                getB = min(b, k);
                getA = k - getB;
            }
            ans += (getA*da + getB*db);
            a-=getA;
            b-=getB;
        }
        cout << ans << '\n';
    }
    return 0;
}