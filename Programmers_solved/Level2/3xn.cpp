#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> dp;
    dp.push_back(3);

    for (int i = 0; i < n/2; i++) {
        dp.push_back((dp[i]*3+2)%1000000007);
    }
    return n%2==0?dp[n/2-1]:0;
    
}