#include <iostream>
using ll = long long;
#define f(a,b,c) for(int a=b; a<c; a++)
using namespace std;

int dx[4] = {-2, -1, 1, 2};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, tmax;
    int bd[1000];
    ll ans = 0;
    f(ee, 1, 11) {
        cin >> N;
        f(i,0,N) cin >> bd[i];
        ans = 0;
        f(k,2,N-2) {
            tmax = 0;
            f(p,0,4) tmax = max(tmax, bd[k-dx[p]]);
            if (bd[k] > tmax) ans+=(bd[k] - tmax);
        }
        cout << '#' << ee <<' ' << ans <<'\n';
    }
    return 0;
}