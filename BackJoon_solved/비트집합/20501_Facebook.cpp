#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
const int N = 2'000;
int n;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n;
    string str;
    vector< bitset<N> > users(n);
    for (int i = 0; i < n; ++i) {
        cin >> str;
        users[i] = bitset<N>(str);
    }
    int q;
    cin >> q;
    int a, b;
    for (int query = 1; query <= q; ++query) {
        cin >> a >> b;
        a--; b--;
        cout << (users[a] & users[b]).count() << '\n';
    }

    return 0;
}