#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
const int inf = 1E6+1;
#define f(a,b,c) for(int a=b; a<c;a++)
pii operator+(const pii& a, const pii& b) { return {a.first+b.first, a.second+b.second};}
int n;
string s[100];
int mp[101][101];
int cost[101][101];
pii mv[4] = {{0,1},{0,-1},{1,0},{-1,0}};

typedef struct _io {
    pii loc; int scst;
} io;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    int sv = T;
    while (T--) {
        cin >> n;
        f(i, 1, n+1) {
            cin >> s[i];
            f(j,1,n+1)
        }
        f(i, 0, n) f(j, 0, n) cost[i][j] = inf;
        cost[0][0] = 0;
        queue<io> q;
        q.push({{0,0},0});
        int ans = inf;
        while (!q.empty()) {
            io dt = q.front(); q.pop();
            f(i, 0, 4) {
                pii nxt = dt.loc + mv[i];
                if (nxt.first < 0 || nxt.first >= n || nxt.second < 0 || nxt.second >= n) continue;
                if (cost[nxt.first][nxt.second] > dt.scst + (s[nxt.first][nxt.second] - '0')) {
                    cost[nxt.first][nxt.second] = dt.scst + (s[nxt.first][nxt.second] - '0');
                    q.push({nxt, cost[nxt.first][nxt.second]});
                }
            }
        }
        cout << '#' << (sv-T) <<". " << cost[n-1][n-1] << '\n';
    }
    return 0;
}