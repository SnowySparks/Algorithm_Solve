#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define N 100'001
const int inf = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> pii;

int study[N];

vector<pii> lst[N];
bitset<N> v;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    priority_queue<pii, vector<pii>, greater<pii> > pq; //<양, idx>

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> study[i];
        pq.push({study[i], i});
    }

    int r; cin >> r;
    for (int i = 0; i < r; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        lst[a].push_back({b, d});
    }

    int ans = 0;

    while (m)
    {   
        while (!pq.empty() && v[pq.top().second]) {
            pq.pop();
        }
        
        int studyCnt = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if (study[idx] < studyCnt) continue;

        ans = max(ans, studyCnt);
        v[idx] = 1;

        for (auto [nxtNode, discountStudy] : lst[idx]) {
            if (!v[nxtNode]) {
                pq.push({study[nxtNode] - discountStudy, nxtNode});
                study[nxtNode]-=discountStudy;
            }
        }
        --m;
    }
    cout << ans;
    
    return 0;
}