#include <iostream>
#include <algorithm>
#define f(a,b,c) for (int a=b ; a<= c ; a++)
using namespace std;
const int inf = 1e5+2;
int dp[inf];
int arr[inf];
int q[inf];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    f(i,1,n) {cin >> arr[i]; dp[arr[i]]++;}
    int m; cin >> m;
    f(i,1,m) cin >> q[i];
    int mv = max(*max_element(arr,arr+n+1),*max_element(q,q+m+1));
    f(i,1,mv) {
        for(int j = 2*i; j <= mv; j+=i) dp[j]+=dp[i];
    }
    f(i,1,m) cout << dp[q[i]] <<' ';
    return 0;
}