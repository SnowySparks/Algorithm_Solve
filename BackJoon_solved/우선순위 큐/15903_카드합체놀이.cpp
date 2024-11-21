#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
#define f(a,b,c) for(int a=b; a<c; a++)
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, t; cin >> N >> M;
    priority_queue<ll,vector<ll>,greater<> > q;
    f(i,0,N) {cin >> t; q.push(t);}
    f(i,0,M) {
        ll a = q.top(); q.pop();
        ll b = q.top(); q.pop();
        ll temp = a+b;
        q.push(temp); q.push(temp);
    }
    ll ans = 0;
    while(!q.empty()) {ans+= q.top(); q.pop();}
    cout << ans; return 0;
}