#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define f(a,b,c) for(int a=b;a<c;a++)
const int inf = 5e5+1;

int p[inf];
int n,m;

int find(int a) {
    if (a == p[a]) return a;
    return p[a] = find(p[a]); }

bool _union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa == pb) return false;
    p[max(pa,pb)] = min(pb,pa);
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int a, b;
    f(i,1,n+1) p[i]=i;
    int ans = 0;
    f(i,1,m+1) {
        cin >> a >> b;
        if (find(a) == find(b)) {
            if (ans==0) ans = i;
        }
        else _union(a,b);
    }
    cout << ans;
    return 0;

}