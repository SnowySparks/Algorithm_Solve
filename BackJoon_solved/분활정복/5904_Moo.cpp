#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1e9+1;
char v[3] = {'m','o','o'};
int t = 3, mid = 3;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n > t) t = 2*t + (++mid);
    while(1) {
        int pre = (t - mid)/2;
        if (n <= pre) {
            mid--;
            t = pre;
        }
        else if (n > pre + mid) {
            n-=(pre+mid);
            mid--;
            t = pre;
        }
        else {
            n-=pre;
            break;
        }
    }

    if (n==1) cout <<'m';
    else cout <<'o';
    return 0;
}