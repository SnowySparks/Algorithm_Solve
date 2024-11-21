#include <iostream>
using namespace std;
#define f(a,b,c) for(int a = b ; a <= c; a++) 

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int h,w,n; cin >> h >> w >> n;
        int x = n%h, y=n/h+1;
        if(!x) {
            x = h;
            y--;
        }
        cout << x*100 + y << '\n';
    }
    return 0;
}