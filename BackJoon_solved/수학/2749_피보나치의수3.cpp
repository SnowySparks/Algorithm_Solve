#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll mdv = 1e6;

vector< vector<ll> > operator* ( vector<vector<ll> > &a, vector<vector<ll> > &b) {
    int N = a.size();
    vector< vector<ll> > result(N, vector<ll>(N,0));
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <N; j ++) {
            for (int k = 0 ; k < N; k ++) {
                result[i][j] += (a[i][k]*b[k][j]);
            }
            result[i][j]%=mdv;
        }
    }
    return result;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    if (n <= 2) {
        cout << 1; return 0; }
    n-=3;
    vector<vector<ll> > v = {{1,1},{1,0}};
    vector<vector<ll> > ans = {{1,1},{1,1}};
    while(n>0) {
        if (n&1) ans = ans * v;
        v =v*v;
        n/=2;
    }
    cout << (ans[1][0] + ans[1][1]) % mdv;
    return 0;
}