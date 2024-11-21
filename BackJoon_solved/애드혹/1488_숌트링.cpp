#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ca, cb, ma, mb; cin >> ca >> cb >> ma >> mb;
    int ans = 0;
    //impossible
    if ((ca == 0 || ma == 0) && (cb == 0 || mb == 0)) cout << 0;
    //possible
    else if ((ca == 0 || ma == 0) ) cout << min(cb,mb);
    else if ((cb == 0 || mb == 0) ) cout << min(ca,ma);

    /*
    else if (abs(ca-cb)<=1) cout << ca+cb;
    else if (ca <= ma && cb <= mb) cout << ca + cb;*/
    
    else {
        if (ca > cb) {
            if ( cb+ 1 >= ( ca/ma + (ca%ma ? 1 : 0) )) cout << ca + cb;
            else cout << cb + (cb + 1)*ma;
        }
        else {
            if ( ca+ 1 >= ( cb/mb + (cb%mb ? 1 : 0) )) cout << ca + cb;
            else cout << ca + (ca + 1)*mb;
        }
    }
    return 0;
}