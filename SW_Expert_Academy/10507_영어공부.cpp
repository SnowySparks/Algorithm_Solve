#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e6+2;
#define f(a,b,c) for (int a=b;a<c;a++)
using pii = pair<int, int>;


bool check[inf];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    memset(check, false, sizeof(check));
    f(i,1,t+1) {
        int n, p; cin >> n >> p;
        int max_val = -1;
        f(t,1,n+1) {
            int d ; cin >> d;
            check[d] = true;
            max_val = max(max_val, d);
        }

        int s = 0, e = 0, cnt = (check[0] ? 1 : 0);
        int ans = 0;

        while (e <= max_val) {
            ans = max(ans, e-s+1);
            if (cnt < p) {
                e++;
                if (!check[e]) cnt++;
            }
            else {
                if (check[e+1]) e++;
                else {
                    if (check[s+1]) s++;
                    else {
                        s++;
                        cnt--;
                    }
                }
            }
        }

        cout << "#" << i << ' ' << ans << "\n";

        f(t,1,max_val+1) check[t] = false;
    }
}