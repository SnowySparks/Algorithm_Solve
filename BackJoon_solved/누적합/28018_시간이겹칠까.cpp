#include <iostream>
#include <algorithm>
#define f(a,b,c) for(int a=b; a<c;a++)
using namespace std;
const int inf = 1E6+2;
int dt[inf] = {0,};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    f(i,0,n) {
        int f,e; cin >> f >> e;
        dt[f]++; dt[e+1]--;
    }
    f(i,1,inf) dt[i] += dt[i-1];
    int q; cin >> q;
    f(i,0,q) {
        int s ; cin >> s;
        cout << dt[s] <<'\n';
    }
    return 0;
}