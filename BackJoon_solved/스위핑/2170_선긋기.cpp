#include <iostream>
#include <algorithm>
using namespace std;
#define f(a,b,c) for(int a = b; a <c; a++)
const int p = 1e6+1;
const int inf = 1e9+2;
pair<int, int> arr[p];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    f(i,0,n) cin >> arr[i].first >> arr[i].second;
    sort(arr,arr+n);
    int st = -inf, end = -inf;
    int ans = 0;
    f(i,0,n) {
        if ( end < arr[i].first) {
            ans += end - st;
            st = arr[i].first;
            end = arr[i].second;
        }
        else end = max(end, arr[i].second);
    }
    ans += end - st;
    cout << ans;
    return 0;

}