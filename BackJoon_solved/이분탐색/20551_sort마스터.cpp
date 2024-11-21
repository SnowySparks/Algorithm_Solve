#include <iostream>
#include <vector>
#include <algorithm>
#define F(a,b,c) for (int a = b; a < c; a++)
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    int t;
    vector<int > dt(N);
    F(i,0,N) {cin >> dt[i];}
    sort(dt.begin(), dt.end());
    F(i,0,M) {
        cin >> t;
        auto loc = lower_bound(dt.begin(), dt.end(), t);
        if (loc == dt.end() || *loc!=t) cout << "-1\n";
        else cout << loc - dt.begin() <<'\n';
    }

}