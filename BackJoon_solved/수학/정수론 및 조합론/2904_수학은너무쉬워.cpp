#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 1'000'001;
int n;
int minimum_primes[N];
int inp[101];
vector<int> primes;
unordered_map<int, int> total_cnt;

int pow(int a, int b) { //a^b
    int res = 1;
    while (b > 0)
    {
        if ( b & 1 ) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
    
}

void init_prime() {
    for (int i = 2; i < N; ++i) {
        if (!minimum_primes[i]) primes.push_back(i);
        for (int prime : primes) {
            if (1LL * prime * i >= 1LL*N) break;
            minimum_primes[ prime * i ] = prime;
            if ( i % prime == 0) break;
        }
    }

}

void cal_all_primes() {
    for (int i = 0; i < n; ++i) {
        int num = inp[i];
        while (minimum_primes[num])
        {   
            total_cnt[ minimum_primes[num] ]++;
            num /= minimum_primes[num];
        }
        total_cnt[num]++; 
    }
}

int cal_all_gcd() {
    int ans = 1;
    for (int i = 0; i < primes.size();  ++i) {
        int prime = primes[i];
        int cnt = total_cnt[prime];

        ans *= pow ( prime, cnt / n );
    }
    return ans;
}

int cnt_move() {
    int ans = 0;
    unordered_map<int ,int> tmp;
    for (int i = 0; i < n; ++i) {
        int num = inp[i];
        // cout << num << "====\n";
        tmp.clear();
        while (minimum_primes[num])
        {   
            tmp[minimum_primes[num]]++;
            num /= minimum_primes[num];
        }
        tmp[num]++;

        for (int prime : primes) {
            if (prime > 1000) break;

            int normal_cnt = total_cnt[prime] / n;
            int cnt = tmp.find(prime) != tmp.end() ? tmp[prime] : 0;

            ans += max(normal_cnt - cnt, 0);
        }
    }
    return ans;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> inp[i];
    init_prime();
    cal_all_primes();
    int gcd = cal_all_gcd();
    int cnt = cnt_move();
    cout << gcd << ' '<< cnt;
    return 0;
}