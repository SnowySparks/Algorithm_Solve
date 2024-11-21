#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, c, a, b; cin >> n >> c;
    while (c--) {
        cin >> a >> b;
        if (a == b) cout << 1;
        else if ( a > b ) cout << ((a-b) - (n-a) <= 2 ? 1 : 0);
        else cout << ((b-a) - (n-b) <= 1 ? 1 : 0 );
        cout <<'\n';
    }
    return 0;
}