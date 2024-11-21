#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> primes;
int arr[1121];
int dp[1121][15]; //n , k

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //making 소수
    for (int i = 2; i<=1120;++i) {
        if (!arr[i]) primes.push_back(i);
        for (int j : primes) {
            if (i*j > 1120) break;
            arr[i*j] = j;
            if (i%j==0) break;
        }
    }

    dp[0][0] = 1; //공집합

    for (int prime : primes) {
        for (int j = 1120 ; j >= 2 ; --j) {
            for (int k = 1 ; k < 15; ++k) {
                if(j - prime >=0) dp[j][k] += dp[j - prime][k-1];
            }
        }
    }

    int t; cin >> t;
    while (--t) {
        int n, k; cin >> n >>k;
        cout << dp[n][k] <<'\n';
    }
    return 0;
}