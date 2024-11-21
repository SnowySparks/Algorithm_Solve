#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 2e9;
#define f(a,b,c) for (int a=b;a<c;a++)
using pii = pair<int, int>;
using ll = long long;
const int inf = 1e9;

bool v[401][401];
int d[401][401];
vector<pii> gh[401];
int ans;
int n, m;

void clear(int n) {
    f(i,0,n) f(j,0,n) {
        v[i][j] = false;
        d[i][j] = 0;
    }

    f(i,0,n) gh[i].clear();
    ans = inf;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    f(t,1,tc+1) {
        cin >> n >> m;
        clear(n);
        f(i,0,m) {
            int s, e, cost; cin >> s >> e >> cost;
            if (s == e) ans = min(ans,cost);
            else {
                gh[i].push_back({e,cost});
            }
        }


        f(i,1,n+1) {
            queue<int> q; q.push(i);
            
        }

        cout << '#' << t << ' ' << ans << '\n';
    }
}