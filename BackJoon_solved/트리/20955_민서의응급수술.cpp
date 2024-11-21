#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int mv = 1e5+1;
int n, m;

int p[mv];

int parent(int a) {
    if (p[a] == a) return a;
    return p[a] = parent(p[a]);
}

bool _union(int a, int b) {
    a = parent(a);
    b = parent(b);
    if (a==b) return false;
    p[max(a,b)] = min(a,b);
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n ; i++) p[i]=i;
    int a, b;
    int ans = 0;
    for (int i = 0 ; i < m ; ++i) {
        cin >> a >> b;
        if (!_union(a,b)) ++ans;
    }
    set<int> st;
    for (int i = 1 ; i <= n ; ++i) st.insert(parent(i));
    cout << ans + ((int)st.size()-1);
    return 0;
}