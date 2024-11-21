#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define f(a,b,c) for(int a=b; a<c; a++)
const int inf = 5e5;

int n; ll k;
ll arr[inf];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    f(i,0,n) cin >> arr[i];
    ll lowk = 0; ll highk = *max_element(arr,arr+n);
    ll ans;
    while (lowk <= highk) {
        ll mid = (lowk + highk)/2;
        ll cnt = 0;
        f(i, 0, n ) cnt += max((ll)0, arr[i]-mid);

        if (cnt > k) {
            lowk = mid + 1;
        }
        else {
            ans = mid;
            highk = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
