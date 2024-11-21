#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> dts;
long long N, P, Q, X, Y;

long long dfs(long long loc) {
    if (loc <= 0) return 1;
    if (dts[loc]) return dts[loc];
    return dts[loc] = dfs(loc/P-X) + dfs(loc/Q-Y);
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> P >> Q >> X >> Y;
    cout << dfs(N);
    return 0;
}