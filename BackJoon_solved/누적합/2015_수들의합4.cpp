#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<long long, long long> dt;
long long ps[200010];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long N, K;
    cin >> N >> K;
    long long n, sum = 0;
    for (int i = 1 ; i <= N ; i++) {
        cin >> ps[i]; 
        ps[i] += ps[i-1];
    }
    long long ans = 0;
    for (int i = 1 ; i <= N ; i++) {
        if (ps[i] == K) ans++;
        ans += dt[ ps[i] - K ];
        dt[ps[i]]++;
    }
    cout << ans;
    return 0;
}