#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define f(a,b,c) for(int a=b; a<c;a++)
using p = pair<int,int>;
const int m = 1e5+1;
int n;
p dt[m];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i,0,n){
        cin >> dt[i].second >> dt[i].first;
        if (dt[i].first < dt[i].second) swap(dt[i].first,dt[i].second);
    }
    int l; cin >> l;
    sort(dt,dt+n);
    int ans = 0;
    priority_queue<int, vector<int> , greater<> > pq;

    f(i,0,n) {
        int e = dt[i].first, s = dt[i].second;
        if (e - s <= l) pq.push(s);

        while(!pq.empty() && e- pq.top() > l) pq.pop();

        ans = max(ans, (int) pq.size());
    }
    cout << ans; return 0;
}