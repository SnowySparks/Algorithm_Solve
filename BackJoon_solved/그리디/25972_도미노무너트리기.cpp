#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
pair<int, int> dt[500000];
int ans = 1;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> dt[i].first >> dt[i].second;
    sort(dt,dt+N);
    int old = dt[0].first + dt[0].second;
    for (int i = 1; i < N; i++) {
        if (old < dt[i].first) ans++;
        old = dt[i].first + dt[i].second;
    }
    cout << ans; return 0;
}