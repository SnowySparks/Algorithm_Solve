#include <iostream>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int N,m, a, b;
    while ( T--) {
        cin >> N >> m;
        while (m--) {
            cin >> a >> b; }
        cout << N-1 <<'\n';
    } return 0;
}