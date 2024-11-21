#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long N; cin >> N;
    long long tp = 0;
    int ans = 1;
    while (1) {
        tp += ans;
        if (tp > N) break;
        ans++;
    }
    if (tp > N) ans--;
    cout << ans;
    return 0;
}