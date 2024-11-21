#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    bool is_not_rime[1000001] = {false,};
    is_not_rime[1] = true;
    for (long long i = 2; i*i<=1000000 ; i++) {
        if (is_not_rime[i]) continue;
        for (long long k = i*i; k<=1000000; k+=i) is_not_rime[k] = true;
    }
    vector<int> primes;
    for (int i = 2 ; i <= 1000000 ; i++) {
        if (!is_not_rime[i]) primes.push_back(i);
    }
    
    int n; cin >> n;
    //2+2+2+2가 최소
    if (n < 8) {cout << -1 ; return 0;}
    vector<int> ans;
    if (n%2==0) {
        ans.push_back(2);
        ans.push_back(2);
        n-=4;
    }
    else {
        ans.push_back(2);
        ans.push_back(3);
        n-=5;
    }

    //투 포인터 접근

    auto l = primes.begin();
    auto r = lower_bound(primes.begin(), primes.end(),n);
    int sum= 0;
    for (int i = 2 ; i <= n/2 ; i++) {
        if (!is_not_rime[i] && !is_not_rime[n-i]) {
            ans.push_back(i);
            ans.push_back(n-i);
            break;
        }
    }
    if (ans.size()!=4) {
        cout << -1; return 0;
    }
    sort(ans.begin(),ans.end());
    for (auto e : ans) {
        cout << e << ' ';
    } return 0;

}