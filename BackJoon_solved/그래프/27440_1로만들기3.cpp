#include <iostream>
#include <queue>
#include <unordered_set>
using ll =unsigned long long;
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N; cin >> N;
    queue<pair<ll,ll> > q;
    unordered_set<ll> m;
    q.push({N,0});
    while(!q.empty()) {
        ll num = q.front().first, p = q.front().second; q.pop();
        if (num == 1) { cout << p; return 0;}
        if (num%3==0 && m.find(num/3) == m.end()) {
            q.push({num/3,p+1});
            m.insert(num/3);
        }
        if (num%2==0 && m.find(num/2) == m.end()) {
            q.push({num/2,p+1});
            m.insert(num/2);
        }
        if (num>1 && m.find(num-1) == m.end()) {
            q.push({num-1,p+1});
            m.insert(num-1);
        }
    }
}