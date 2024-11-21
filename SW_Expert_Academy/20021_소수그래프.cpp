#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool temp_prime[1101];
vector<int> prime;

void circle_print(int n) {
    for (int i = 1; i <= n-1 ; ++i) {
        cout << i << ' ' << (i +1) <<'\n';
    }
    cout << n << ' ' << 1 <<'\n';
}

void cross_print(int n, int left) {
    for (int i = 1; i <= left; ++i) {
        cout << i <<' ' << (i + n/2) <<'\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //에라토스테네스 체
    for (int i = 2; i*i <= 1100; ++i) {
        if (temp_prime[i] == false) {
            for (int j = i+i; j <= 1100; j+=i) temp_prime[j] = true;
        }
    }
    for (int i = 2; i <= 1100; ++i) {
        if (!temp_prime[i]) prime.push_back(i);
    }
    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n; cin >> n;
        int nxtprime = *lower_bound(prime.begin(), prime.end(), n);
        cout << nxtprime <<'\n';
        circle_print(n);
        if (n != nxtprime) {
            cross_print(n, nxtprime - n);
        }
    }
    return 0;
}