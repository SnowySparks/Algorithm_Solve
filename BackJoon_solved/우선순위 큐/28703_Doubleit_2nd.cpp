#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> lst(n);
    f(i,0,n) cin >> lst[i];
    int mx = *max_element(lst.begin(), lst.end());
    for (int &a : lst) {
        while (2*a <= mx) a *=2;
    }
    sort(lst.begin(),lst.end());
    int ans = lst.back() - lst.front();
    f(i,1,n) ans = min(ans, lst[i-1]*2 - lst[i]);
    cout<<ans;
    return 0;
}