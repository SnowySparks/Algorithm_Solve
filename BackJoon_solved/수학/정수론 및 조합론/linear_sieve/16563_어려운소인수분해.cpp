#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int inf = 5e6+1;
vector<int> prime; //소수들
int sz[inf]; // 0 :  소수 , 다른값 : 최소 (소수)소인수

void linear_sieve(int n) {
    for (int i = 2; i <= n ; i++) {
        if (sz[i] == 0) prime.push_back(i);
        for (int &e : prime) {
            if (i*e > n) break;
            sz[i*e]=e;
            if(i%e==0)break;
        }
    }
}

int n, tmp;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; linear_sieve(inf-1);
    while(n--) {
        cin >> tmp;
        while (sz[tmp]) {
            cout << sz[tmp] <<' '; tmp/=sz[tmp];
        }
        cout << tmp << '\n';
    }
    return 0;
}