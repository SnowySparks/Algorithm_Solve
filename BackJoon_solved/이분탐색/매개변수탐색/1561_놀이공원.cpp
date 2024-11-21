#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dt[10001];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M ; i++) cin >> dt[i];
    if ( N <= M) {cout << N; return 0; }
    long long minv = 0, maxv = 6E10 + 1;
    long long mid ;
    long long sum = 0;
    long long ttime = 0;
    while (minv <= maxv) {
        mid = (minv + maxv) /2;
        sum = M;
        for (int i =1 ; i <= M ; i++) sum+= (mid/dt[i]);
        if (sum >= N) {ttime = mid; maxv= mid-1;}
        else minv = mid+ 1;
    }
    long long calp = M;
    // 정확히 1분전 
    for (int i = 1; i <= M ; i++) {
        calp += (ttime -1) / dt[i];
    }
    for (int i = 1; i <= M ; i++) {
        if (ttime % dt[i] == 0) calp++;
        if (calp == N) {
            cout << i << '\n'; break;
        }
    }
    return 0;
}