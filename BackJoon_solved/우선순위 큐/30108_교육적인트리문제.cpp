#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 3e5 + 1;
vector<int> adj[N];
int val[N];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int n; cin >> n;
    int parent;
    
    for (int i = 2; i <= n; ++i) {
        cin >> parent;
        adj[parent].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> val[i];
    
    priority_queue<pair<int ,int> > pq; // <값, 노드>
    pq.push({val[1], 1});
    
    long long ans = 0;
    while (!pq.empty())
    {
        int value = pq.top().first;
        int loc = pq.top().second;
        pq.pop();

        ans += 1LL * value;

        cout << ans << '\n';

        for (int nxtNode : adj[loc]) {
            pq.push({val[nxtNode], nxtNode});
        }
    }

    return 0;
}