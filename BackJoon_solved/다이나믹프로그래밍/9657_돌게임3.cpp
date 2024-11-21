#include <iostream>
#include <vector>
using namespace std;

bool w[1001]; //true:sk, false cy

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    
    w[1] = true; w[2] = false; w[3] = true; w[4] = true; w[5] = true; w[6] = true;
    for (int i = 8 ; i <= n ; i++) {
        if (!(w[i-1] && w[i-3] && w[i-4])) w[i] = true;
        else w[i] = false;
    }
    cout << (w[n] ? "SK" : "CY");
    return 0;
}