#include <iostream>
#include <cstring>
#include <algorithm>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
const int max_sum = 1e5;
int n;
bool dp[max_sum+1];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    int tmp;
    int total = 0;
    f(i,0,n) {
        cin >> tmp;
        total += tmp;
        for (int j = max_sum; j >= tmp; --j) {
            if (dp[j-tmp]) dp[j] = true;
        }
    }
    if (total % 2 == 0 && dp[total/2]) {
        cout << "Yes";
    }
    else cout << "No";
    return 0;
}
