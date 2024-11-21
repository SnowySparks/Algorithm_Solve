#include <iostream>
#include <cmath>
#define f(a,b,c) for (int a = b ; a < c ; a++)
using d = double;
using namespace std;
d dist(const pair<d,d>&a, const pair<d,d>&b) { return sqrt( pow(a.first - b.first,2) + pow(a.second - b.second,2)); }
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    pair<d,d> start, end, dt;
    d r;
    int ans = 0;
    while(T--) {
        cin >> start.first >> start.second >> end.first >> end.second;
        int N; cin >> N;
        ans = 0;
        f(i,0,N) {
            cin >> dt.first >> dt.second >> r;
            d from = dist(dt,start), to = dist(dt,end);
            if (from < r && to < r) continue;
            else if (from > r && to > r) continue;
            else ans++;
        }
        cout << ans <<'\n';
    }
    return 0;
}