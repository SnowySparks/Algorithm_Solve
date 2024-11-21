#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int room[1000001];

int main(void) {
    int N; cin >> N;
    for (int i = 0 ; i < N ; i++) {
        cin >> room[i];
    }
    int b,c; cin >>b >> c;
    long long ans = 0;

    for (int i = 0 ; i < N ; i++) {
        room[i] -= b; ans++;
        if (room[i] > 0) {ans+=(room[i]/c + (room[i]%c==0 ? 0 : 1));}
    }
    cout << ans;
}