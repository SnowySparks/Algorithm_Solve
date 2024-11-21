#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int b;
    cin >> b;
    vector<int> input(b);
    for (int i=0; i<b; i++) {
        cin>>input[i];
    }
    int a=*max_element(input.begin(), input.end());
    vector<long long> dp = {0,1,1,1};

    for (int i=4;i<=a;i++) {
        dp.push_back(dp[i-2]+dp[i-3]);
    }
    
    for (auto e : input) {
        cout<<dp[e]<<endl;
    }

    return 0;

}