#include <iostream>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int cnt = 1;
    while (true) {
        if (N - cnt <=0) break;
        N-= cnt; cnt++;}
    if (cnt % 2 == 0) cout << (N) << '/' << (cnt - N + 1);
    else cout << (cnt - N + 1) << '/' << N;
    return 0;
}