#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#define f(a, b, c) for(int a=b;a<c;++a)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
const int MAXN = 5e5 + 1;
int n, m;
pll buyer[MAXN]; // [l, r]
pli seller[MAXN];// [가격, 개수]

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> m;
    f(i, 0, n) cin >> buyer[i].first >> buyer[i].second;
    f(i, 0, m) cin >> seller[i].first >> seller[i].second;
    sort(buyer, buyer+n);
    sort(seller, seller+m);
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    int buyIdx = 0;
    int answer = 0;

    f(sellIdx, 0, m) {
        while (buyIdx < n && seller[sellIdx].first >= buyer[buyIdx].first) {
            pq.push(buyer[buyIdx++].second);
        }
        while (!pq.empty() && pq.top() < seller[sellIdx].first)
        {
            pq.pop();
        }
        while (!pq.empty() && seller[sellIdx].second > 0)
        {
            pq.pop();
            ++answer;
            seller[sellIdx].second--;
        }
        
    }
    cout << answer;
    return 0;
}