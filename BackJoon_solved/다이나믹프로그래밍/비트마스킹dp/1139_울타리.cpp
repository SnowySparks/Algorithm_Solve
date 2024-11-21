#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
using d = double;
#define f(a,b,c) for (int a = b; a < c ; a++)
d dp[1<<16];
int arr[16];
int n;
d cals(int a, int b, int c) {
    d p = (d)(a+b+c)/(2.0);
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

d dfs(int bit) {
    d &res = dp[bit];
    if (res >= 0.0) return res;
    res = 0.0;
    f(i,0,n) f(k,i+1,n) f(j,k+1,n) {
        int rbit = (1<<i)|(1<<k)|(1<<j);
        if ( (bit & rbit) == 0 && (arr[i] + arr[j] > arr[k]) ) {
            d p = ((d)(arr[i] + arr[j] + arr[k]))/(2.0);
            d cal = sqrt(p * (p-arr[i]) * (p-arr[j]) * (p-arr[k]) );
            res = max(res, dfs(bit|rbit) + cal);
        }
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cout<<fixed;
    cout.precision(9);
    for(int i = 0 ; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);
    memset(dp,-1,sizeof(dp));
    cout << dfs(0);

    return 0;
}