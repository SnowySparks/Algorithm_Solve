#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int p = 1e5+1;
#define f(a,b,c) for (int a = b ; a <= c ; a++) 
int res[p]; bool v[p];

int nxt(int n) {
    int c1 = 0, c2 = 1;
    int tmp = n;

    while (tmp) {
        c1 += tmp%10;
        tmp/=10;
    }
    tmp = n;
    while (tmp) {
        c2 *= (tmp%10);
        tmp/=10;
    }
    return stoi( to_string(c1) + to_string(c2));
}

int dfs(int n) {
    if (n >= p) return -1;
    if (v[n]) {
        if (res[n] == -2) return res[n] = 0;
        else return res[n];
    }
    v[n] = true;
    int r = nxt(n);
    if (r > 100000) return res[n] = -1;
    if (n == r) {
        v[r] = true;
        res[r] =1;
        return res[n] = 1;
    }
    return res[n] = dfs(r);
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    f(i,1,p-1) res[i] = -2;
    //10배수는 무조건 됨
    for (int i = 10 ; i <p; i+= 10) {
        v[i] = true; res[i] = 1;
    }
    f(i,1,p-1) if (!v[i]) res[i] = dfs(i);
    int l, r; cin >> l >> r;
    int ans = 0;
    f(i,l,r) ans+= res[i];
    cout << ans;
    return 0;
}