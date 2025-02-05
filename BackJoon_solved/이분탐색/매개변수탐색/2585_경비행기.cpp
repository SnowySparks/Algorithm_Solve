#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define f(a, b, c) for(int a=b; a<c; ++a)
using namespace std;
using pii = pair<int ,int>;
const int N = 1e3 + 2;
int n,k;
pii cord[N];
int fuel[N][N];
int v[N];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cord[0] = {0, 0};
    f(i, 1, n+1) cin >> cord[i].first >> cord[i].second;
    cord[n+1] = {10000, 10000};

    f(i, 0, n+1) {
        f(j, i+1, n+2) {
            double dist = sqrt(pow((cord[i].first - cord[j].first),2) + pow((cord[i].second - cord[j].second),2));
            fuel[i][j] = ceil(dist/10);
            fuel[j][i] = fuel[i][j];
        }
    }

    int l = 0, r = 20000;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        memset(v, -1, sizeof(v));
        v[0] = 0;
        queue<pii> q; q.push({0, mid});

        while (!q.empty())
        {
            auto [loc, leftFuel] = q.front(); q.pop();
            if (v[loc] >= k) continue;
            f(i, 1, n+2) {
                if (v[i] != -1 || i == loc) continue;
                if (leftFuel >= fuel[loc][i]) {
                    v[i] = v[loc];
                    q.push({i, leftFuel - fuel[loc][i]});
                }
                else if (fuel[loc][i] <= mid) {
                    v[i] = v[loc] + 1;
                    q.push({i, mid - fuel[loc][i]});
                }
            }
        }
        if (v[n+1] != -1) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
        
    }
    cout << ans;
    return 0;
}