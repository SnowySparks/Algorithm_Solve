#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#define f(a,b,c) for(int a=b; a<=c; a++)
using namespace std;
const int inf = 1e6+1;
int idx[inf];
int n; 
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int dp = 0;
    cin >> n;
    idx[0] = -1;
    f(i,1,n) {
        int tmp ; cin >> tmp;
        idx[tmp] = i;
    }
    int ans = -1;
    f(i,1,n) {
        if (idx[i-1] < idx[i]) dp++;
        else dp= 1;
        ans = max(ans, dp);
    }
    cout << n - ans ; return 0;
}