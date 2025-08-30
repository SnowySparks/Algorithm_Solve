#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N, K, C;
int things[5001];
long long prefix[5001];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);

    cin >> N >> K >> C;
    for (int i = 1 ; i <= N; ++i) cin >> things[i];
    sort(things+1, things + 1+N);
    for (int i = 1 ; i <= N; ++i) prefix[i] = prefix[i-1] + things[i];

    int idx = 0;

    for (int x = 1; x <= C; ++x) {
        while (idx < N && prefix[idx+1] <= x && N - idx > K) ++idx;
        cout << prefix[min(N, idx+K)] - prefix[idx] << '\n';
    }

    return 0;
}