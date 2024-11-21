#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int a;
    cin >> a;

    vector<int>arr(a), dp(a);
    for (int i=0; i<a; i++) {
        cin >> arr[i];
    }

    dp[0]=arr[0];

    for (int i=1; i<a; i++) {
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
    }

    cout<<*max_element(dp.begin(),dp.end())<<endl;
    return 0;
 
}