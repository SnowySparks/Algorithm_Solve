#include <iostream>
#include <cstring>
#include <algorithm>
#define f(a,b,c) for (int a=b ; a< c ; a++)
using namespace std;
using pii = pair<int, int>;
int n, m;
pii dv[1000];
bool v[1001];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(v,false,sizeof(v));
        f(i,0,m) {
            cin >> dv[i].second >> dv[i].first;
        }
        int ans =0;
        sort(dv,dv+m,less<pii>());
        f(i,0,m) {
            f(k, dv[i].second, dv[i].first+1) {
                if (!v[k]) {
                    v[k] = true;
                    ans++;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}