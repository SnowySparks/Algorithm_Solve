#include <iostream>
#include <algorithm>
using namespace std;
#define f(a,b,c) for(int a=b; a<c; a++)

int p[502];

int parent(int n) {
    if (n == p[n]) return n;
    else return p[n] = parent(p[n]);
}

void _unite(int a, int b) {
    a = parent(a);
    b = parent(b);
    if (a!=b) p[max(a,b)] = min(a,b);   
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m ;
    f(i,1,n+1) p[i]=i;
    f(i,0,m) {
        int a, b; cin >> a >> b;
        _unite(a,b);
    }
    f(i,1,n+1) cout << parent(i) <<' ';
    int ans =0;
    f(i,2,n+1) if (parent(i) == 1) ans++;
    cout << ans; return 0;
}