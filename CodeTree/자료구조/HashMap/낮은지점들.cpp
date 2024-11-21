#include <iostream>
#include <unordered_map>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unordered_map<int , long long> pts;
    int n; cin >> n;
    int x; long long y;
    f(i, 0, n) {
        cin >> x >> y;
        if (pts.find(x) == pts.end() || pts[x] > y) pts[x] = y; 
    }
    long long ans = 0;
    for (pair<int, long long> item : pts) {
        ans+=item.second;
    }
    cout << ans;
}