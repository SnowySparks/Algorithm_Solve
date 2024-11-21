#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    int inp, ans;
    for (int i =1 ; i <= T; i++) {
        ans = 0;
        for (int j = 0 ; j < 10 ; j++) {
            cin >> inp;
            if (inp%2) ans+=inp;
        }
        cout << '#' << i <<' '<<ans <<'\n';
    }
    return 0;
}